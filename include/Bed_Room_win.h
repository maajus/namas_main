/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bed_Room_win.h
 * Author: justas
 *
 * Created on September 28, 2016, 7:53 PM
 */

#ifndef BED_ROOM_WIN_H
#define BED_ROOM_WIN_H



#include "ui_Bed_Room_win.h"
#include "definitions.h"
#include "info_widget.h"
#include "Room.h"
#include "TCP.h"
#include <QThread>

class Bed_Room_win : public QDialog {
    Q_OBJECT
public:
    Bed_Room_win(info_widget*);
    virtual ~Bed_Room_win();
    void update_info();
    void update_room_info();
    void send_tcp_cmd(QString);
    Room* get_room();
    void status_xml(QDomDocument *);
    
private:
    Ui::Bed_Room_win widget;
    info_widget *info_w;
    Room *room;
    QThread *tcp_thread;
    Room_status status;
    int connection_status;

private slots:
    void room_status_received(Room_status);
    void set_connection_status(int);
    void on_lights0_button_clicked();
    void on_lights1_button_clicked();
    void on_lights2_button_clicked();

    void on_back_button_clicked();
//    void checkBox_stateChanged(int);
};

#endif /* _ROOM_WIN_H */
