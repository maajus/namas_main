/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCP.cpp
 * Author: justas
 * 
 * Created on August 6, 2016, 7:49 PM
 */

#include "TCP.h"
#include <QDebug>
#include <QObject>
#include <QSignalMapper>
#include "Bath_Room_win.h"


TCP::TCP() {
    
    socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect(socket, SIGNAL(readyRead()),this, SLOT(readTcpData()));
    //this->connect2room();
    retry_count = 0;
    
}

TCP::~TCP() {
}



void TCP::connect2room(){
    
    socket->connectToHost(ip,5555);
        
    emit connected(Status::CONNECTING);
    //qDebug()<<"Connecting";
    if( socket->waitForConnected(300)) {
        qDebug()<<"[TCP] Connected to "<<ip;
        emit connected(Status::CONNECTED);
    }
    //else{
        //qDebug()<<"[TCP] Timeout, failed to connect "<<ip;
    //}
}

void TCP::readTcpData()
{
    QByteArray Data = socket->readAll();
    //qDebug()<<data;
    emit dataReceived(Data);
}

void TCP::sendData(QByteArray data){

    if(socket->state()==QTcpSocket::ConnectedState){
        socket->write( data );
        //socket->waitForReadyRead();
        socket->waitForBytesWritten();
    }

    else{
        if(retry_count<=3){
            qDebug()<<"[TCP] Try to reconnect ip: "<<ip;
            this->connect2room();
            retry_count++;
        }
        else {
            emit connected(Status::FAILED);
            qDebug()<<"[TCP] Timeout, failed to connect "<<ip;
        }
    }

}

void TCP::set_ip(QString ipaddr){
    
    ip = ipaddr;
}


//void TCP::connect_thread(QThread *thread){

    //connect(thread, SIGNAL(started()), this, SLOT(connect2room()));

//}

