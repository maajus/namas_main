/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCP.h
 * Author: justas
 *
 * Created on August 6, 2016, 7:49 PM
 */

#ifndef TCP_H
#define TCP_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QThread>
#include <QList>

enum Status{
    DISCONNECTED,
    CONNECTED,
    CONNECTING,
    FAILED,

};
    

class TCP : public QObject
{
    Q_OBJECT
    
public:
    TCP();
    virtual ~TCP();
    
    void sendData(QByteArray data);
    void set_ip(QString);
    //void connect_thread(QThread*);
    void connect2room();

    
private:
    
   //QByteArray data;
    QString ip;
  QTcpSocket* socket;
  int retry_count;

  
  
private slots:
    void readTcpData();

signals:
    void dataReceived(QByteArray);
    void connection_failed(QAbstractSocket::SocketError);
    void connected(int);
};

#endif /* TCP_H */

