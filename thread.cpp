/**
 * @file thread.cpp
 * @author DingKun & ChengLei
 * @date 2022.3.15
 * @brief The file contains the details about implementation of three thread class SendThread,RecvThread,SaveThread and one class SaveBuf
 * @details SendThread sends image to python.RecvThread receives mask image from python.SaveThread save three
 * images by turns.SaveBuf maintenances the saved images.
 */

#include "thread.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "modbus.h"


#define FIFO_PATH "/tmp/dkimg.fifo"
#define FIFO_MASK "/tmp/dkmask.fifo"
#define FIFO_RGB "/tmp/dkrgb.fifo"
#define FIFO_MASK_RGB "/tmp/dkmask_rgb.fifo"

#define ACQUISITION_ENABLE

extern QSemaphore ready_to_send;
extern QSemaphore ready_to_send_rgb;
extern int file_threshold;
extern int file_threshold_rgb;
extern int file_padding;

extern float* send_buf;
extern float* send_valid_buf;

extern uint8_t* send_rgb_buf;

extern modbus_t* plc;

uint8_t* recvbuf = nullptr;
uint8_t* recvbuf_rgb = nullptr;
extern uint8_t* temp_rgb;

extern Camera* camera;

SaveBuf* save_buf_queue = new SaveBuf();

uint8_t* merge_mask = new uint8_t[256 * 1024];
uint8_t* merge_mask_rgb = new uint8_t[256 * 1024];
//uint8_t* merge_bit2byte = new uint8_t[32 * 1024];
//uint8_t* merge_bit2byte_rgb = new uint8_t[32 * 1024];

uint8_t* send_mask_guo = new uint8_t[32 * 1024];

SendThread::SendThread(QObject *parent) : QThread(parent)
{
    recvbuf = new uint8_t[SPEC_MASK_HEIGHT * SPEC_MASK_WIDTH];
    recvbuf_rgb = new uint8_t[RGB_MASK_HEIGHT * RGB_MASK_WIDTH];
}

SendThread::~SendThread()
{
    if( recvbuf ) delete recvbuf;
    if( recvbuf_rgb ) delete recvbuf_rgb;
}

void SendThread::run()
{
    //建立管道
    if(access(FIFO_PATH, F_OK) == -1)
    {
        int res = mkfifo(FIFO_PATH, 0777);
        if(res < 0)
        {
            cout << "make img fifo failed!" << endl;
            return;
        }
    }
    if(access(FIFO_MASK, F_OK) == -1)
    {
        int res = mkfifo(FIFO_MASK, 0777);
        if(res < 0)
        {
            cout << "make mask fifo failed!" << endl;
            return;
        }
    }
    if(access(FIFO_RGB, F_OK) == -1)
    {
        int res = mkfifo(FIFO_RGB, 0777);
        if(res < 0)
        {
            cout << "make rgb fifo failed!" << endl;
            return;
        }
    }
    if(access(FIFO_MASK_RGB, F_OK) == -1)
    {
        int res = mkfifo(FIFO_MASK_RGB, 0777);
        if(res < 0)
        {
            cout << "make mask_rgb fifo failed!" << endl;
            return;
        }
    }

    int fd_img = open(FIFO_PATH, O_WRONLY);
    int fd_rgb = open(FIFO_RGB, O_WRONLY);

    string str = to_string(file_threshold);
    int ret = write(fd_img, str.c_str(), str.size());
    if(ret > 0)
        cout << ">>> spec threshold " << file_threshold << " send to python" << endl;

    str = to_string(file_threshold_rgb);
    ret = write(fd_rgb, str.c_str(), str.size());
    if(ret > 0)
        cout << ">>> rgb threshold " << file_threshold_rgb << " send to python" << endl;

    uint8_t padding_hash[256] = {0};
    uint8_t padding_hash_rgb[256] = {0};

    while(1)
    {
        ready_to_send.acquire();   //block if no send_buf is ready!
        ready_to_send_rgb.acquire();

        int k = 0;
        for( int i = 0; i < SPEC_HEIGHT; i++ )
        {
            for(uint j = 0; j < valid.size(); j++ )
            {
                memcpy(send_valid_buf + SPEC_WIDTH * k, send_buf + (i * camera->m_height + valid[j]) * 1024,
                       sizeof(float) * SPEC_WIDTH);
                k++;
            }
        }
        /*存图功能*/

        if(save_flag == true)
        {
            static int file_index = 0;
            string spec_filename = "./saved_img/spec" + to_string(file_index);
            FILE *fp = fopen(spec_filename.c_str(), "wb");
            fwrite(send_valid_buf, SPEC_HEIGHT * SPEC_WIDTH * valid.size() * 4, 1, fp);
            fclose(fp);
            string rgb_filename = "./saved_img/rgb" + to_string(file_index);
            fp = fopen(rgb_filename.c_str(), "wb");
            fwrite(send_rgb_buf, RGB_HEIGHT * RGB_WIDTH * 3, 1, fp);
            fclose(fp);
            file_index++;
            cout << "save img success!" << endl;
        }
        ///////////////////////////////

        //发送给python
        write(fd_img, send_valid_buf, SPEC_WIDTH * valid.size() * SPEC_HEIGHT * sizeof(float));

        write(fd_rgb, send_rgb_buf, RGB_HEIGHT * RGB_WIDTH * 3);

        int fd = open(FIFO_MASK, O_RDONLY);
        read(fd, recvbuf, SPEC_MASK_HEIGHT * SPEC_MASK_WIDTH);
        close(fd);
        fd = open(FIFO_MASK_RGB, O_RDONLY);
        read(fd, recvbuf_rgb, RGB_MASK_HEIGHT * RGB_MASK_WIDTH);
        close(fd);

//        save_buf_queue->enqueue(send_valid_buf, (char*)recvbuf);

        //send mask to ui
        emit send_mask((char*)recvbuf);   //mask*********************************************
        emit send_mask_rgb((char*)recvbuf_rgb);

        /*mask图像转换喷阀通道  宽度1024像素对应256个喷阀，1024/256=4，每一行转换为256个bit，
         *总共32个字节，最终发送给下位机的数据大小为(32*1024字节)*/

        //光谱mask阀通道转换
        int sum = 0;
        for(int i=0; i<SPEC_MASK_HEIGHT*SPEC_MASK_WIDTH; i+=4)
        {
            sum = recvbuf[i] + recvbuf[i+1] + recvbuf[i+2] + recvbuf[i+3];
            (sum > 0) ?  (merge_mask[i/4] = 1) :  (merge_mask[i/4] = 0);
            sum = 0;
        }
        //rgb mask阀通道转换
        sum = 0;
        for(int i=0; i<RGB_MASK_HEIGHT*RGB_MASK_WIDTH; i+=4)
        {
            sum = recvbuf_rgb[i] + recvbuf_rgb[i+1] + recvbuf_rgb[i+2] + recvbuf_rgb[i+3];
            (sum > 0) ?  (merge_mask_rgb[i/4] = 1) :  (merge_mask_rgb[i/4] = 0);
            sum = 0;
        }

        //延长喷阀开启时间，纵向拉长像素
        uint8_t temp_buf[1024 * 256] = {0};
        for(int i=0; i<1024; ++i)
        {
            if(i == 0)
            {
                for(int j=0; j<256; ++j)
                {
                    while(padding_hash[j] > 0)
                    {
                        temp_buf[padding_hash[j]*256 + j] = 1;
                        --padding_hash[j];
                    }
                }
            }
            for(int j=0; j<256; ++j)
            {
                if(merge_mask[i * 256 + j] == 1)
                {
                    temp_buf[i * 256 + j] = 1;
                    int padding = 0;
                    while(padding < file_padding)
                    {
                        if(i + padding >= 1024)
                        {
                            padding_hash[j] = file_padding - padding;
                            break;
                        }
                        else
                        {
                            temp_buf[(i + padding) * 256 + j] = 1;
                            ++padding;
                        }
                    }
                }
            }
        }

        uint8_t temp_buf_rgb[1024 * 256] = {0};
        for(int i=0; i<1024; ++i)
        {
            if(i == 0)
            {
                for(int j=0; j<256; ++j)
                {
                    while(padding_hash_rgb[j] > 0)
                    {
                        temp_buf[padding_hash_rgb[j]*256 + j] = 1;
                        --padding_hash_rgb[j];
                    }
                }
            }
            for(int j=0; j<256; ++j)
            {
                if(merge_mask_rgb[i * 256 + j] == 1)
                {
                    temp_buf_rgb[i * 256 + j] = 1;
                    int padding = 0;
                    while(padding < file_padding)
                    {
                        if(i + padding >= 1024)
                        {
                            padding_hash_rgb[j] = file_padding - padding;
                            break;
                        }
                        else
                        {
                            temp_buf_rgb[(i + padding) * 256 + j] = 1;
                            ++padding;
                        }
                    }
                }
            }
        }

        //计算喷伐开启次数
        /*
        for(int i=0; i<REALHEIGHT; ++i)
        {
            for(int j=0; j<256; ++j)
                valve_cnt[j] += merge_mask[i*REALHEIGHT+j];
        }
        */
//        for(int i=0; i<256*1024; i+=8)
//        {
//            uint8_t temp = 0;
//            for(int j=7; j>=0; --j)
//                temp = (temp << 1) | temp_buf[i + j];
//            merge_bit2byte[i/8] = temp;
//        }
//        for(int i=0; i<256*1024; i+=8)
//        {
//            uint8_t temp = 0;
//            for(int j=7; j>=0; --j)
//                temp = (temp << 1) | temp_buf_rgb[i + j];
//            merge_bit2byte_rgb[i/8] = temp;
//        }
        //合并两个mask
        for(int i=0; i<256*1024; i+=8)
        {
            uint8_t temp = 0;
            uint8_t temp_rgb = 0;
            for(int j=7; j>=0; --j)
            {
                temp = (temp << 1) | temp_buf[i + j];
                temp_rgb = (temp_rgb << 1) | temp_buf_rgb[i + j];
            }
            temp |= temp_rgb;
            send_mask_guo[i/8] = temp;
        }

        emit send_valve_data(send_mask_guo);
    }
}

SaveBuf::SaveBuf()
{
    buf = new float[SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT * SAVEIMGNUMBER];
    mask = new char[1024 * 256 * SAVEIMGNUMBER];
    buf_copy = new float[SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT * SAVEIMGNUMBER];
    mask_copy = new char[1024 * 256 * SAVEIMGNUMBER];
}

SaveBuf::~SaveBuf()
{
    delete [] buf;
    delete [] mask;
    delete [] buf_copy;
    delete [] mask_copy;
}

void SaveBuf::enqueue(float* buf_tmp, char* mask_tmp)
{
    mutex.lock();
    memcpy(buf + index * SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT, buf_tmp, SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT * 4);
    memcpy(mask + index * 1024 * 1024, mask_tmp, 1024 * 1024);
    mutex.unlock();
    index++;
//    cout << "save index ==================" << index << endl;
    if(index >= SAVEIMGNUMBER)
        index = 0;
}

void SaveBuf::save()
{
    mutex.lock();
    memcpy(buf_copy, buf, SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT * SAVEIMGNUMBER * 4);
    memcpy(mask_copy, mask, 1024 * 1024 * SAVEIMGNUMBER);
    mutex.unlock();
    char* filename;
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyyMMddhhmmss");
    for( int i = 0; i < SAVEIMGNUMBER; i++)
    {
        QString mask_name = str + "mask" + QString::number(i);
        filename = mask_name.toLatin1().data();
        FILE* fp = fopen(filename, "wb");
        fwrite(mask_copy + i * 1024 * 1024, 1024 * 1024, 1, fp);
        fclose(fp);

        QString buf_name = str + "buf" + QString::number(i) + ".raw";
        filename = buf_name.toLatin1().data();
        fp = fopen(filename, "wb");
        fwrite(buf_copy + i * SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT, SPEC_WIDTH * VALIDBANDS * SPEC_HEIGHT * 4, 1, fp);
        fclose(fp);
        cout << ">>> save success";
    }
}

//savethread保存图片线程，该线程保持一个环形队列始终存放实时图像
SaveThread::SaveThread(QObject *parent) : QThread(parent)
{}

void SaveThread::run()
{
//    cout << "save thread running" << endl;
    while (1)
    {

        save_flag.acquire();
        save_buf_queue->save();
        cout << "acquired!!" << endl;
    }
}

