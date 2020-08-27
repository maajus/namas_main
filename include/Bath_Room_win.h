/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bath_Room_win.h
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#ifndef _ROOM_WIN_H
#define _ROOM_WIN_H



#include "ui_Bath_Room_win.h"
#include "definitions.h"
#include "info_widget.h"
#include "Room.h"
#include <QThread>

class Bath_Room_win : QObject {
    Q_OBJECT
public:
    Bath_Room_win();
    virtual ~Bath_Room_win();
    void update_info();
    void send_tcp_cmd(QString);
    Room* get_room();

private:
    Ui::Bath_Room_win widget;
    Room *room;
    Room_status status;
    int connection_status;

private slots:
    void room_status_received(Room_status);
    void set_connection_status(int);
};

#endif /* _ROOM_WIN_H */
