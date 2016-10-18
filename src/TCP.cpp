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
#include "Room_win.h"

QString room_ip[5] = {
    "192.168.1.66",
    "192.168.1.165",
    "192.168.1.166",
    "192.168.1.167",
    "192.168.1.168"
};

TCP::TCP(int id):room_id(id) {
    
    socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
    connect(socket, SIGNAL(readyRead()),this, SLOT(readTcpData()));
    this->connect2room();
    
}

TCP::~TCP() {
}




void TCP::connectTcp()
{

//    socket = new QTcpSocket( this ); // <-- needs to be a member variable: QTcpSocket * _pSocket;
//    connect(socket, SIGNAL(readyRead()),this, SLOT(readTcpData()));
//
//    socket->connectToHost("192.168.1.66"/*room_ip[room_id]*/,5555);
//    //qDebug()<<"Connecting";
//    if( socket->waitForConnected(4000)) {
//        //qDebug()<<"Sending data";
//        socket->write( data );
//    }
}

void TCP::connect2room(){
    
    
    socket->connectToHost(room_ip[room_id],5555);
        
    //qDebug()<<"Connecting";
    if( socket->waitForConnected(1000)) {
        qDebug()<<"[TCP] Connected to "<<room_ip[room_id];
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
        qDebug()<<"[TCP] Try to reconnect";
        this->connect2room();
    }

}

void TCP::set_id(int id){
    
    room_id = id;
    
}