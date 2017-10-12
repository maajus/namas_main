/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainWindow.h
 * Author: justas
 *
 * Created on August 6, 2016, 5:03 PM
 */

#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QTimer>
#include "ui_MainWindow.h"
#include "TCP.h"
#include "Bath_Room_win.h"
#include "Bed_Room_win.h"
#include "Corridor_win.h"
#include "Living_Room_win.h"
#include "Bed_Room_win.h"
#include "Work_Room_win.h"
#include "Camera.h"
#include "GPIO.h"

enum Menus{

    HOME,
    AUDIO,
    SECURITY,
    CAMERA,
    SETTINGS,

};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:        
    MainWindow();
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
    TCP *server;
    QTimer status_timer;
    QTimer info_timer;
    Bath_Room_win *bathroom;
    Bed_Room_win *bedroom;
    Work_Room_win *workroom;
    Corridor_win *corridor;
    GPIO *gpio;
    Camera *cam;
    
private slots:
    void on_leave_button_clicked();
    void on_take_photo_button_clicked();
    void on_rec_button_clicked();
    void update_status();
    void update_info();
    void menu_selected(int);
    void gpio_interrupt(int);
};

#endif /* _MAINWINDOW_H */
