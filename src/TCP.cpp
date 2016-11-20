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

QString room_ip[5] = {
    "192.168.1.67",
    "192.168.1.165",
    "192.168.1.166",
    "192.168.1.167",
    "192.168.1.67"
};

TCP::TCP(int id):room_id(id) {
    
    socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect(socket, SIGNAL(readyRead()),this, SLOT(readTcpData()));
    this->connect2room();
    retry_count = 0;
    
}

TCP::~TCP() {
}



void TCP::connect2room(){
    
    
    socket->connectToHost(room_ip[room_id],5555);
        
    emit connected(Status::CONNECTING);
    //qDebug()<<"Connecting";
    if( socket->waitForConnected(1000)) {
        qDebug()<<"[TCP] Connected to "<<room_ip[room_id];
        emit connected(Status::CONNECTED);
    }
    else{
        qDebug()<<"[TCP] Timeout, failed to connect "<<room_ip[room_id];
    }
}

void TCP::readTcpData()
{
    QByteArray Data = socket->readAll();
    //qDebug()<<data;
    emit dataReceived(Data);
}

void TCP::sendData(QByteArray data){

    if(socket->state()==QTcpSocket::ConnectedState)
        socket->write( data );
    else{
        if(retry_count<=3){
            qDebug()<<"[TCP] Try to reconnect";
            this->connect2room();
            retry_count++;
        }
        else {
            emit connected(Status::FAILED);
        }
    }

}

void TCP::set_id(int id){
    
    room_id = id;
    
}
