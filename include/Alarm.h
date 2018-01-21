
#ifndef _ALARM_H
#define  _ALARM_H

#include <QString>
#include <QJsonValue>
#include <QJsonObject>

//class User {

    //public:
        //QString name;
        //QString key;

        //QJsonObject toJson() const {
          //return {{"name", name}, {"key", key}};
        //}

//};

class Alarm
{

    public:
        Alarm();
        int arm_system();
        QString disarm_system(QString code);
        bool isArmed();
        //QString check_key(QString);
        //int readUsers(QList<User> *users);
        //int writeKeys();

    private:
        bool armed;


};


#endif
