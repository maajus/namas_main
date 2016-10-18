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

class TCP : public QObject
{
    Q_OBJECT
    
public:
    TCP(int id);
    virtual ~TCP();
    
    void connect2room();
    void sendData(QByteArray data);
    void set_id(int id);
    
private:
    
   //QByteArray data;
   int room_id;
  QTcpSocket* socket;

  
  
private slots:
    void readTcpData();
    void connectTcp();
    signals:
    void dataReceived(QByteArray);
    void connection_failed(QAbstractSocket::SocketError);
};

#endif /* TCP_H */

