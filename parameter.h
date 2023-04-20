#ifndef PARAMETER_H
#define PARAMETER_H

#include "camera.h"
#include <QTime>




class Parameter{
public:
    QTime lamp_timer;
    QTime work_timer;
    uint32_t lamp_used_time = 0;
    string password;
    vector<string> file_info = vector<string>(3);
    uint32_t valve_cnt_vector[256] = {0};
    QDateTime current_time;
    QTime starttime;
    QTime stoptime;
    uint32_t runtime;
};




#endif // PARAMETER_H
