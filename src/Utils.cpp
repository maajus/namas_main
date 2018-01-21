/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <QByteArray>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QNetworkInterface>
#include <QRegExpValidator>
#include <QProcess>
#include "Utils.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "miniaes.h"
#include "Config.h"



QHostAddress Utils::get_ip(QString interface){

    QNetworkInterface iface = QNetworkInterface::interfaceFromName(interface);
    QList<QNetworkAddressEntry> entries = iface.addressEntries();
    if (!entries.isEmpty()) {
        QNetworkAddressEntry entry = entries.first();
        QHostAddress ip = entry.ip();
        return ip;
    }
    return (QHostAddress::Null);


}


bool Utils::fileExists(QString path) {

    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        return true;
    } else {
        return false;
    }
}


void Utils::char_to_number(unsigned char *data){

    for (int i = 0; i < 32; i++) {
        if(data[i] > 0) data[i] = data[i] - 0x30;
    }
}



//QString  Utils::readMac(){

    ////find eth mac addr
    //QNetworkInterface face = QNetworkInterface::interfaceFromName("eth0");
    //if (face.isValid())
        //return face.hardwareAddress();
    //else
        //return QObject::tr("N/A");

//}

//void Utils::rotate_logs(){

    //QFileInfo info("/var/log/applog");
    //if(info.size() > MAX_APP_LOG_SIZE){

        //system("mv /var/log/applog1 /var/log/applog2");
        //system("mv /var/log/applog /var/log/applog1");

    //}


    //QFileInfo info1(LOG_FILE);
    //if(info1.size() > MAX_APP_LOG_SIZE){

        //system("mv " LOG_FILE "1 " LOG_FILE "2");
        //system("mv " LOG_FILE " " LOG_FILE "1");

    //}


/*}*/

QByteArray Utils::encodeString(QByteArray data){

    MiniAES crypto;
    QByteArray password = HARD_KEY;
    QByteArray iv;
    iv.fill(0x00,16);
    return crypto.Encrypt(data, password, iv);
}


QByteArray Utils::decodeString(QByteArray data){

    MiniAES crypto;
    QByteArray password = HARD_KEY;
    QByteArray iv;
    iv.fill(0x00,16);
    //qDebug()<<aes_key <<" size: "<<aes_key.size();
    return crypto.Decrypt(data, password, iv);
}

bool Utils::isProcessRunning(QString name){

    QProcess proc;
    proc.start(SCRIPT_DIR "isProcessRunning "+name);
    proc.waitForFinished(1000);
    return proc.exitCode();

}

bool Utils::isVolumeMounted(QString name){

    QProcess proc;
    proc.start(SCRIPT_DIR "volume_mounted "+name);
    proc.waitForFinished(1000);
    return proc.exitCode();

}


