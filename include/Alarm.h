
#ifndef _ALARM_H
#define  _ALARM_H

#include <QString>

class User {

    public:
        QString name;
        QString key;

};

class Alarm
{

    public:
        Alarm();
        int arm_system();
        int disarm_system(QString code);
        bool isArmed();
        bool check_key(QString);
        QStringList readKeys();
        int writeKeys();






    private:
        bool armed;


};


#endif
