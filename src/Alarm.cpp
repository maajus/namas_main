#include "Alarm.h"
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QFile>
#include "Config.h"


Alarm::Alarm(){

    armed = false;

}

int Alarm::arm_system(){

    armed = true;
    return true;

}

QString Alarm::disarm_system(QString code){

    if(!armed) return "";
    QString user = this->check_key(code);
    if(!user.isEmpty()){
        armed = false;
        return user;
    }
    else {
         return "";
    }


}

QString Alarm::check_key(QString code){

    QList<User> users;
    this->readUsers(&users);

    for(int i = 0; i < users.size(); i++){
        if(users.at(i).key == code)
            return users.at(i).name;
    }

    return "";
}

bool Alarm::isArmed(){

    return armed;

}

int Alarm::readUsers(QList<User> *users){

    QFile jsonFile("/home/pi/samba/users.json");
    if(!jsonFile.open(QIODevice::ReadOnly)){
        qDebug()<<"[Alarm] Failed to open ";//<<USERS_FILE;
        return 1;
    }

    QString val = jsonFile.readAll();
    QJsonDocument doc = QJsonDocument().fromJson(val.toUtf8());
    if(doc.isNull()){
        qDebug()<<"[Alarm] Failed to read users json";
        return 1;
    }
    QJsonArray array = doc.array();

    for(int i = 0; i < array.size(); i++)
    {

        User user;
        user.name = array.at(i).toObject()["name"].toString();
        user.key = array.at(i).toObject()["key"].toString();
        users->append(user);

    }

    jsonFile.close();
    return 0;

}

int Alarm::writeKeys(){


    QList<User> users{{"Justas", "00000"}, {"Sima", "12345"}};
    users.push_back({"antanas","99999"});

    //QJsonObject Users;
    QJsonArray users_array;
    for(int i = 0; i < users.size(); i++){

        users_array.push_back(users[i].toJson());

    }

    //Users.insert("Users",users_array);

    QJsonDocument doc(users_array);

    QFile jsonFile("/home/pi/samba/users.json");
    if(!jsonFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        qDebug()<<"[Alarm] Failed to open ";//<<USERS_FILE;
    jsonFile.write(doc.toJson());
    jsonFile.close();

    return 0;

}




