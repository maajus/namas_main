#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QDebug>
#include <QDomDocument>

struct User {
    QString username;
    QString pass;

    bool operator==(const User& user)
    {

        if( (username == user.username) && 
         (pass == user.pass)
         ) 
            return true;
        else
            return false;

    }


};

class UserManager
{
    public:
    UserManager();
    void addUser(User user);
    void removeUser(User user);
    int login(User *user, QString *username);
    User get_user(int);
    void clear_users();
    


    private:
    int readUsers();
    int writeUsers();
    void xml_to_users(QDomDocument *domdoc, QList<User> *userlist);
    void user_to_xml(QDomDocument * domdoc, QList<User> *userlist);
    QList<User> userlist;



};

#endif
