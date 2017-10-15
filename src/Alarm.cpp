#include "Alarm.h"
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include "Config.h"


Alarm::Alarm(){

}

int Alarm::arm_system(){

    armed = true;
    return true;

}

int Alarm::disarm_system(QString code){

    if(!armed) return 1;

    if(this->check_key(code)){
        armed = false;
        return true;
    }
    else {
        return false;
    }


}

bool Alarm::check_key(QString code){

    Q_UNUSED(code);
    return false;
}

bool Alarm::isArmed(){

    return armed;

}

QStringList Alarm::readKeys(){

}

int Alarm::writeKeys(){


    QList<User> users{{"Justas", "00000"}, {"Sima", "12345"}};

    QJsonObject Users;
    QJsonArray users_array;
    users_array.push_back("+44 1234567");
    users_array.push_back("+44 2345678");
    Users.insert("Users",users_array);

    QJsonDocument doc(Users);

    QFile jsonFile("./user.json");
    if(jsonFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
        qDebug()<<"[Alarm] Failed to open ";//<<USERS_FILE;
    jsonFile.write(doc.toJson());
    jsonFile.close();


qDebug()<<doc.toJson(QJsonDocument::Compact);

return 0;

}




