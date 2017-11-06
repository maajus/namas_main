/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MainWindow.cpp
 * Author: justas
 *
 * Created on August 6, 2016, 5:03 PM
 */

#include "MainWindow.h"
#include "info_widget.h"
#include <QDateTime>
#include <QFile>
#include <QObject>
#include <QFontDatabase>
#include "Logger.h"
#include "Config.h"

MainWindow::MainWindow() {

#ifndef PC
    gpio = new GPIO();
    connect(gpio, &GPIO::gpio_interrupt, this, &MainWindow::gpio_interrupt);
#endif

    widget.setupUi(this);

    connect(&status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    connect(&info_timer, SIGNAL(timeout()), this, SLOT(update_info()));
    connect(widget.side_menu,SIGNAL(currentRowChanged(int)),SLOT(menu_selected(int)));

    status_timer.start(STATUS_REFRESH);
    info_timer.start(ROOM_INFO_UPDATE_FREQ);

    widget.bedroom_info->set_name("Miegamasis");
    widget.workroom_info->set_name("Darbo Kambarys");
    widget.corridor_info->set_name("Koridorius");
    widget.livingroom_info->set_name("Salionas");
    widget.wc_info->set_name("Vonia");

    bathroom = new Bath_Room_win(widget.wc_info);
    connect(widget.wc_info,SIGNAL(clicked()), bathroom, SLOT(show()));

    bedroom = new Bed_Room_win(widget.bedroom_info);
    connect(widget.bedroom_info,SIGNAL(clicked()), bedroom, SLOT(show()));

    workroom = new Work_Room_win(widget.workroom_info);
    connect(widget.workroom_info,SIGNAL(clicked()), workroom, SLOT(show()));

    corridor = new Corridor_win(widget.corridor_info);
    connect(widget.corridor_info,SIGNAL(clicked()), corridor, SLOT(show()));

    livingroom = new Living_Room_win(widget.livingroom_info);
    connect(widget.livingroom_info,SIGNAL(clicked()), livingroom, SLOT(show()));

    qApp->installEventFilter(this); //install event filter to catch mouse events

    widget.arm_alarm_label->setText("Arm alarm");
    widget.alarm_button->setIconSize(QSize(120,120));
    widget.alarm_button->setIcon(QIcon(":/icons/locked.png"));


    QFontDatabase::addApplicationFont(":/fonts/digital.ttf");
    QFont font = QFont("Digital-7", 42, 1);
    widget.time_label->setFont(font);
    widget.date_label->setFont(font);
    widget.date_label->setStyleSheet("color:#4c4c4c");

    //QFontDatabase db;
    //qDebug()<<db.families();

    //Load and apply stylesheet
    QFile stylesheet(qApp->applicationDirPath()+"/formStyle.css");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    qApp->setStyleSheet(setSheet);
    widget.side_menu->setIconSize(QSize(64, 64));
    widget.side_menu->setCurrentRow(0);
    this->update_status();

    connect(widget.key_1, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_2, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_3, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_4, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_5, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_6, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_7, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_8, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_9, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.key_0, &QPushButton::clicked, this, &MainWindow::key_clicked);
    connect(widget.del_key, &QPushButton::clicked, this, &MainWindow::key_clicked);

    //cam = new Camera;
    //if(cam->available()){
    //cam->set_widget(widget.video_widget);
    //cam->start();
    //}


    alarm = new Alarm();
    QList<User> users;



    widget.keypad_widget->setEnabled(false);



    //alarm->readUsers(&users);
    //alarm->writeKeys();
    //qDebug()<<alarm->check_key("99999");

}

MainWindow::~MainWindow() {
}

void MainWindow::on_take_photo_button_clicked(){

    cam->take_photo();

}

void MainWindow::on_rec_button_clicked(){

    cam->capture_photo();

}

//void MainWindow::on_leave_button_clicked(){

    //exit(0);
//}



void MainWindow::update_status(){

    widget.date_label->setText(QDateTime::currentDateTime().toString("yyyy.MM.dd"));
    widget.time_label->setText(QDateTime::currentDateTime().toString("hh:mm"));
    gpio->idle_timer_increment();

}

void MainWindow::update_info(){

    bathroom->update_info();
    workroom->update_info();
    corridor->update_info();
    bedroom->update_info();
    livingroom->update_info();
}

void MainWindow::menu_selected(int menu){

    widget.stack_widget->setCurrentIndex(menu);
    //if(menu == Menus::CAMERA){
    //if(cam->available())  cam->start();
    //}
    //else
    //if(cam->available()) cam->stop();

}


void MainWindow::gpio_interrupt(int intnr){

    switch(intnr){
        case INT_DOOR_OPEN:
            Logger::log(LOG_TRIGGERS, "Door opened");
            break;

    }
}

void MainWindow::key_clicked(){

    QString obname = QObject::sender()->objectName();
    QString text = widget.alarm_code_lineedit->text();


    if(obname == "del_key"){

        text.chop(1);

    }

    if(text.size() >= 5) return;

    if(obname.mid(0,3) == "key"){

        text.append(obname.mid(4));
    }

    widget.alarm_code_lineedit->setText(text);

    if(alarm->isArmed()){
        if(text.size() == 5)
            widget.alarm_button->setEnabled(true);
        else
            widget.alarm_button->setEnabled(false);
    }

}

void MainWindow::on_alarm_button_clicked(){


    if(alarm->isArmed()){
        QString key = widget.alarm_code_lineedit->text();
        widget.keypad_widget->setEnabled(true);
        QString user = alarm->disarm_system(key);
        if(!user.isEmpty()){//code ok

            qDebug()<<"[MainWindow] Alarm disabled by: "<<user;
            widget.keypad_widget->setEnabled(false);
            widget.alarm_button->setEnabled(true);

        }
        else{//wrong code

            qDebug()<<"[MainWindow] Wrong alarm code entered: "<<key;
            widget.alarm_code_lineedit->setText("");
            widget.alarm_button->setEnabled(false);

        }
    }
    else{

        qDebug()<<"[MainWindow] Alarm is armed";
        alarm->arm_system();
        widget.keypad_widget->setEnabled(true);
        widget.alarm_button->setEnabled(false);
    }

    widget.alarm_code_lineedit->setText("");

}


//catch mouse events, to turn on backlight on touch
bool MainWindow::eventFilter(QObject *obj, QEvent *event) {

    Q_UNUSED(obj);

    if ((event->type() == QEvent::MouseMove) || (event->type() == QEvent::MouseButtonDblClick) \
            || (event->type() == QEvent::MouseButtonPress) || (event->type() == QEvent::MouseMove)\
            || (event->type() == QEvent::MouseButtonRelease)) {

        //qDebug()<<event;
        //reset idle counter
        gpio->reset_idle_timer();
    }

    return false;

}

