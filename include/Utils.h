/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: justas
 *
 * Created on April 13, 2016, 12:47 PM
 */

#ifndef UTILS_H
#define UTILS_H

#include <bitset>
#include <QByteArray>
#include <QString>
#include <QHostAddress>

class Utils{
    public:

        static bool fileExists(QString path);
        static void char_to_number(unsigned char *data);
        static QHostAddress get_ip(QString interface);
        //static void rotate_logs();
        static bool isProcessRunning(QString name);
        static bool isVolumeMounted(QString name);

        static QByteArray encodeString(QByteArray);
        static QByteArray decodeString(QByteArray);
};




















#endif /* UTILS_H */

