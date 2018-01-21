#include "UserManager.h"
#include <QFile>
#include "Config.h"
#include "Utils.h"

UserManager::UserManager(){

    this->readUsers();
}


void UserManager::addUser(User user){
    
    userlist.push_back(user);
    this->writeUsers();

}

void UserManager::removeUser(User user){

    if(!userlist.removeOne(user))
        qDebug()<<"[UserManager] Failed to remove user "<<user.username;

}

User UserManager::get_user(int id){

    if(id >= userlist.count()) return User();
    return userlist.at(id);
}

void UserManager::clear_users(){

    userlist.clear();
    this->writeUsers();
}

int UserManager::login(User *user, QString *username){

    for(int i = 0; i < userlist.count(); i++) {

        if(!user->username.isEmpty()){
            //usrname found
            if(userlist.at(i).username == user->username){
                //pass matced
                if(userlist.at(i).pass == user->pass){
                    this->writeUsers();
                    *username = userlist.at(i).username;
                    return 0;
                }
                else return 2;//wrong pass
            }

        }

    }
    return 4; //wrong username
}



int UserManager::readUsers() {

    QDomDocument domdoc;
    QString errorStr;
    int errorLine;
    int errorColumn;
    QFile file;

    file.setFileName(CONFIG_DIR "users.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "[UserManager] Failed to open "<<file.fileName();
        return 1;
    }

    if (!domdoc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
        qDebug() << "[UserManager] Users " << errorStr << errorLine << errorColumn;
        return 1;
    }

    xml_to_users(&domdoc, &userlist);
    file.close();
    return 0;
}



void UserManager::xml_to_users(QDomDocument *domdoc, QList<User> *userlist) {


    QDomElement root = domdoc->firstChildElement();
    QDomElement root1 = root.firstChildElement();
    QDomNodeList items = root1.elementsByTagName("User");
    if (items.count() <= 0) return;
    //qDebug() << "[Rx Timers] Node found : " << items.count();
    //parse TX


    for (int i = 0; i < items.count(); i++) {

        if (items.at(i).isElement()) {
            QDomElement userItem = items.at(i).toElement();
            User user;
            user.username =  userItem.firstChildElement("username").text();
            user.pass=Utils::decodeString(QByteArray::fromBase64(userItem.firstChildElement("pass").text().toLatin1()));
            userlist->push_back(user);
        }
    }
}


void UserManager::user_to_xml(QDomDocument * domdoc, QList<User> *userlist) {

    //if (timers.size() <= 0) return;
    QDomElement root, root1, root2, element, element1;
    //root = domdoc->firstChildElement();
    root = domdoc->createElement("UserList");
    root1 = domdoc->createElement("Users");

    for (int i = 0; i < userlist->count(); i++) {

        root2 = domdoc->createElement("User");

        element = domdoc->createElement("username");
        element.appendChild(domdoc->createTextNode(userlist->at(i).username));
        root2.appendChild(element);

        element = domdoc->createElement("pass");
        element.appendChild(domdoc->createTextNode(QString(Utils::encodeString(userlist->at(i).pass.toLatin1()).toBase64())));
        root2.appendChild(element);

        root1.appendChild(root2);
    }
    root.appendChild(root1);
    domdoc->appendChild(root);

}


int UserManager::writeUsers(){

    QFile file(CONFIG_DIR "users.xml");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "[UserManager] Failed to open "<<file.fileName();
        return 1;
    }

    QDomDocument domdoc;
    this->user_to_xml(&domdoc, &userlist);

    file.seek(0);
    file.resize(0);
    QTextStream stream(&file);
    //qDebug()<<domdoc.toString();
    stream << domdoc.toString();
    file.close();
    return 0;

}



