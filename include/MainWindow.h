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
#include "Alarm.h"
#include "ws_server.h"
#include "Settings.h"
#include "json.hpp"

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

    bool eventFilter(QObject *obj, QEvent *event);


private:
    void LoadSettings();
    void SwitchAllLights(bool);

    Ui::MainWindow widget;
    QTimer status_timer;
    QTimer info_timer;
    Room *bathroom;
    Room *livingroom;
    Room *bedroom;
    Room *workroom;
    Room *corridor;
    WSserver *ws_server;
    Settings *settings;

    GPIO *gpio;
    Camera *cam;
    Alarm *alarm;

private slots:

    void WS_dataReceived(QWebSocket *pClient, nlohmann::json j);
    //void on_leave_button_clicked();
    void on_take_photo_button_clicked();
    void on_settings_save_button_clicked();
    void on_rec_button_clicked();
    void on_alarm_button_clicked();
    void on_all_lights_on_button_clicked();
    void on_all_lights_off_button_clicked();
    void update_status();
    void update_info();
    void menu_selected(int);
    void gpio_interrupt(int);
    void key_clicked();
};

#endif /* _MAINWINDOW_H */
