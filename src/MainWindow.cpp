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

MainWindow::MainWindow() {

    gpio = new GPIO();

/*
    widget.setupUi(this);
    
    
    connect(&status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    connect(&info_timer, SIGNAL(timeout()), this, SLOT(update_info()));
    connect(widget.side_menu,SIGNAL(currentRowChanged(int)),SLOT(menu_selected(int)));
    
    status_timer.start(1500);
    info_timer.start(2000);
    
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


    cam = new Camera;
    if(cam->available()){
        cam->set_widget(widget.video_widget);
        cam->start();
    }
    */
}

MainWindow::~MainWindow() {
}

void MainWindow::on_take_photo_button_clicked(){

    cam->take_photo();

}

void MainWindow::on_rec_button_clicked(){

    cam->capture_photo();

}

void MainWindow::on_leave_button_clicked(){
    
  exit(0); 
}



void MainWindow::update_status(){
    
    widget.date_label->setText(QDateTime::currentDateTime().toString("yyyy.MM.dd"));
    widget.time_label->setText(QDateTime::currentDateTime().toString("hh:mm"));
    
}

void MainWindow::update_info(){
    
    bathroom->update_info();
    workroom->update_info();
    corridor->update_info();
    bedroom->update_info();
    this->repaint();
}

void MainWindow::menu_selected(int menu){

    widget.stack_widget->setCurrentIndex(menu);
    //if(menu == Menus::CAMERA){
        //if(cam->available())  cam->start();
    //}
    //else
        //if(cam->available()) cam->stop();

}
