
#ifndef _ALARM_H
#define  _ALARM_H

#include <QString>

class Alarm
{

    public:
        Alarm();
        int arm_system();
        int disarm_system(QString code);
        bool isArmed();
        QStringList readKeys();



    private:
        bool armed;


};


#endif
