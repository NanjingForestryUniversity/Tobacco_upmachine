#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"
#include "camera.h"
#include "fstream"
#include "parameter.h"
#include "modbus.h"

#define MODE_SET_ADDR               0x0800
#define CONVEYOR_ADDR               0x0A0F
#define LAMP_ADDR                   0x0A0E
#define POWER_ADDR                  0x0A12
#define DRAUGHT_FAN_ADDR            0x0A13
#define BRUSH_ADDR                  0x0A14
#define LAMP_FORCE                  0x0814

#define CONVEYOR_AUTO_ADDR          0x0A26
#define LAMP_AUTO_ADDR              0x0A27
#define BRUSH_AUTO_ADDR             0x0A28
#define POWER_AUTO_ADDR             0x0A29
#define DRAUGHT_FAN_AUTO_ADDR       0x0A2A

namespace Ui {
class Widget;
}
// THIS IS THE FIRST M
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    SendThread* send_thread = nullptr;
    SaveThread* save_thread = nullptr;

    cv::Mat img;
    cv::Mat img_rgb;
    QTcpServer* server_to_lowermachine = nullptr;
    QTcpSocket* lower_machine = nullptr;

    QTcpSocket* up_machine = nullptr;  //上位机socket

    Parameter* parameter = nullptr;

    bool connect_to_monitor = false;
    bool send_to_up_machine = false;

    volatile bool is_running = false;

    void set_spinbox_range();
    void set_ui(bool fullscreen);
    void connect_monitor();
    void load_parameter_doc();
    void load_system_parameter();
    void connect_signal();

    //communication protocal 通信协议
    void send_after_start();

    //记录相机开启关闭日志
    void time_log(int state);

    void send_lamp_time_to_monitor();

    void restart_from_error();//2022.8.8

    int connect_modbus();

    int plc_command(int times, int coil_addr, int status);

    int plc_open_power();

    int plc_close_power();

    int plc_auto_start();

    int plc_auto_stop();

private slots:
    void get_data(uint8_t* buff);
    void get_rgb_data(uint8_t* buff);

    void On_btn_start_clicked();

    void On_btn_stop_clicked();

    void On_btn_black_clicked();  //采集黑帧图片

    void On_btn_white_clicked();  //采集白帧图片

    void On_btn_capture_clicked();

    void get_mask(char* get_buf);

    void get_mask_rgb(char* get_buf);

    void get_valve_data(uint8_t* valve_data);

    void get_send_to_up_machine(float* sendbuf);

    void readfrom_up_machine();

    void readfrom_lower_machine();//2022.8.8

    void On_btn_sendsingle_clicked();

    void On_btn_autosend_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_clear_clicked();

    void on_btn_del_clicked();

    void on_btn_ensure_clicked();

    void on_btn_back_clicked();

    void on_btn_send_plus_clicked();

    void on_btn_send_min_clicked();

    void On_btn_threshold_clicked();

    void on_btn_set_lower_clicked();

    void on_btn_set_camera_clicked();

    void on_btn_set_clicked();

    void on_btn_rgb_white_clicked();

    void on_btn_rgb_black_clicked();

    void on_btn_save_enable_clicked();

    void on_btn_save_disenable_clicked();



    void on_btn_open_conveyor_clicked();

    void on_btn_close_conveyor_clicked();

    void on_btn_open_lamp_clicked();

    void on_btn_close_lamp_clicked();


    void on_btn_exit_2_clicked();

    void on_btn_0to3_2_clicked();

    void on_btn_send_single_long_clicked();

    void on_btn_autosend_valve_clicked();

    void on_radioButton_manul_2_clicked(bool checked);

    void on_radioButton_manul_clicked(bool checked);

    void on_btn_lamp_reset_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
