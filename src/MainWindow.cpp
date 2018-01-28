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
#include <QProcess>
#include "Logger.h"
#include "Config.h"
#include "UserManager.h"

MainWindow::MainWindow() {

    gpio = new GPIO();
    connect(gpio, &GPIO::gpio_interrupt, this, &MainWindow::gpio_interrupt);
    server = new Server();
    settings = new Settings();
    widget.setupUi(this);

  connect(server, SIGNAL(dataReceived(Tcp_packet *, int)), this, SLOT(TCP_dataReceived(Tcp_packet *, int)));
    //connect(server, SIGNAL(connection_status(int)), this, SLOT(Remote_connected(int)));
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

    widget.alarm_button->setIconSize(QSize(120,120));
    widget.arm_alarm_label->setText("Įjungti signalizaciją");
    widget.alarm_button->setIcon(QIcon(":/icons/locked.png"));
    widget.alarm_status_label->setPixmap(QPixmap(":/icons/unlocked.png"));

    QFontDatabase::addApplicationFont(":/fonts/digital.ttf");
    QFont font = QFont("Digital-7", 42, 1);
    widget.time_label->setFont(font);
    widget.date_label->setFont(font);
    widget.date_label->setStyleSheet("color:#282828");

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

    widget.pir1_label->setVisible(gpio->read(GPIO_PIR));
    alarm = new Alarm();



    widget.keypad_widget->setEnabled(false);
    this->LoadSettings();


    //alarm->readUsers(&users);
    //alarm->writeKeys();
    //qDebug()<<alarm->check_key("99999");
    
    //User user1, user2;
    //user1.username = "Justas";
    //user1.pass = "22334";
    //user2.username = "Sima";
    //user2.pass = "11234";
    //UserManager manager;
    //manager.addUser(user1);
    //manager.addUser(user2);
    //manager.writeUsers();


}

MainWindow::~MainWindow() {
}

void MainWindow::on_take_photo_button_clicked(){

    cam->take_photo();

}

void MainWindow::on_rec_button_clicked(){

    cam->capture_photo();

}


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
            {
                Logger::log(LOG_TRIGGERS, "Door opened");
                //if pir = 0 door should be opened from outside
                if(gpio->read(GPIO_PIR) == 0){
                    if(settings->DoorLight()) corridor->send_tcp_cmd("L2");
                    if(settings->DoorSiren())  gpio->siren_beep();
                }
                else{ //door opened from inside
                    if(settings->DoorLight()){
                        if(corridor->GetStatus().L[2] == 1) //if corridor lights if on turn them off
                            corridor->send_tcp_cmd("L2");
                    }
                }

                if(alarm->isArmed()){
                    QProcess proc;
                    proc.startDetached("/home/pi/scripts/sendEmail \"Durys atsidare!\"");
                    //system("/home/pi/scripts/sendEmail \"Durys atsidare!\"");
                }
                break;
            }

        case INT_PIR_ON:
            if(settings->PirLcd()) gpio->reset_idle_timer();
            widget.pir1_label->setVisible(true);
            break;

        case INT_PIR_OFF:
            widget.pir1_label->setVisible(false);
            break;
    }
}

void MainWindow::key_clicked(){

    QString obname = QObject::sender()->objectName();
    QString text = widget.alarm_code_lineedit->text();

    //backspace
    if(obname == "del_key"){
        text.chop(1);
        widget.alarm_code_lineedit->setText(text);
        return;
    }

    //already enough symbols
    if(text.size() >= 5) return;

    //append pressed number
    if(obname.mid(0,3) == "key"){
        text.append(obname.mid(4));

        widget.alarm_code_lineedit->setText(text);

        if(alarm->isArmed()){
            if(text.size() == 5)
                widget.alarm_button->setEnabled(true);
            else
                widget.alarm_button->setEnabled(false);
        }
    }
}
void MainWindow::on_all_lights_on_button_clicked(){

    this->SwitchAllLights(true);

}

void MainWindow::on_all_lights_off_button_clicked(){

    this->SwitchAllLights(false);

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
            widget.arm_alarm_label->setText("Įjungti signalizaciją");
            widget.alarm_button->setIcon(QIcon(":/icons/locked.png"));
            widget.alarm_status_label->setPixmap(QPixmap(":/icons/unlocked.png"));

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
        widget.arm_alarm_label->setText("Išjungti signalizaciją");
        widget.alarm_button->setIcon(QIcon(":/icons/unlocked.png"));
        widget.alarm_status_label->setPixmap(QPixmap(":/icons/locked.png"));
        this->SwitchAllLights(false);



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




//tcp packet received
void MainWindow::TCP_dataReceived(Tcp_packet *tcp_Packet,int socket_id) {

    //qDebug() << "Received command: " << tcp_Packet->command << "Object: " << tcp_Packet->object;

    if (tcp_Packet->command == "Get") {
        this->TCP_response_to_get(tcp_Packet, socket_id);
        return;
    }
    if (tcp_Packet->command == "Set") {
        this->TCP_response_to_set(tcp_Packet, socket_id);
        return;
    }

    qDebug() << "[MainWindow] Unknown command from remote: " << tcp_Packet->command;
    server->format_and_send_packet("Rx", "ResponseTo" + tcp_Packet->command, tcp_Packet->object, "Error", "Unknown Command", socket_id);

}


//send requested data over tcp
void MainWindow::TCP_response_to_get(Tcp_packet *tcp_Packet, int socket_id) {

    Tcp_packet * tcp_packet = new Tcp_packet;
    tcp_packet->command = "ResponseToGet";
    tcp_packet->object = tcp_Packet->object;
    tcp_packet->sender = "Rx";

    QDomElement element, root;

    if (tcp_Packet->object == "Status") {

        root = tcp_packet->dataE.createElement("Status");
        tcp_packet->dataE.appendChild(root);

        corridor->status_xml(&tcp_packet->dataE);
        livingroom->status_xml(&tcp_packet->dataE);
        bedroom->status_xml(&tcp_packet->dataE);
        bathroom->status_xml(&tcp_packet->dataE);
        workroom->status_xml(&tcp_packet->dataE);

        //element = tcp_packet->dataE.createElement("FreeMemory");
        //element.appendChild(tcp_packet->dataE.createTextNode(QString::number(rxstatus.FreeMemory)));
        //root.appendChild(element);

        //element = tcp_packet->dataE.createElement("TotalMemory");
        //element.appendChild(tcp_packet->dataE.createTextNode(QString::number(rxstatus.TotalMemory)));
        //root.appendChild(element);


        tcp_packet->status = "Ok";
        server->process_data(tcp_packet,socket_id);

        //qDebug().noquote()<<tcp_packet->dataE.toString();
        delete tcp_packet;
        return;
    }

    if (tcp_Packet->object == "Log") {

        //tcp_packet->status = "Ok";
        //if(!obj_created.LOG_window){
            //obj_created.LOG_window = true;
            //logwindow = new LOG_window();
        //}
        //logwindow->get_log_xml(tcp_packet, tcp_Packet);

        server->process_data(tcp_packet,socket_id);
        delete tcp_packet;
        return;
    }

    if (tcp_Packet->object == "Settings") {

        //qDebug() << "[Remote] Sending rx settings to remote";
        tcp_packet->status = "Ok";
        if(settings->get_config(tcp_packet)){
            tcp_packet->status = "Error";
            tcp_packet->error = "failed to read rx settings";
        }

        //qDebug()<<tcp_packet->dataE.toString();
        server->process_data(tcp_packet,socket_id);
        delete tcp_packet;
        return;
    }

  if (tcp_Packet->object == "Login") {

        //qDebug().noquote()<<tcp_Packet->dataE.toString();
        tcp_packet->status = "Ok";
        struct User user;
        QDomElement root_element = tcp_Packet->dataE.firstChildElement();
        user.username = root_element.firstChildElement("username").text();
        user.pass = root_element.firstChildElement("pass").text();

        if(user.username == "-1" && user.pass == "-1"){
            qDebug()<<"[MainWindow] Bad login";
        }
        else{

            UserManager manager;
            QString username;
            int status = manager.login(&user,&username);

            QDomElement root, root1;
            root = tcp_packet->dataE.createElement("Login");
            root1 = tcp_packet->dataE.createElement("status");
            root1.appendChild(tcp_packet->dataE.createTextNode(QString::number(status)));
/*            if(!status){*/
                //com_thread->log(Strings::webuser_login(user.username));
                //com_thread->set_webGui(user.username);
            /*}*/
            root.appendChild(root1);
            root1 = tcp_packet->dataE.createElement("username");
            root1.appendChild(tcp_packet->dataE.createTextNode(user.username));
            root.appendChild(root1);

            tcp_packet->dataE.appendChild(root);
            server->process_data(tcp_packet,socket_id);
        }


        //qDebug().noquote()<<tcp_packet->dataE.toString();
        //tcp_packet->error = "";
        delete tcp_packet;
        return;

    }



    qDebug() << "Unknown object" << tcp_Packet->object;
    server->writeData("Unknown Object", socket_id);
    //delete tcp_Packet;
    delete tcp_packet;
    return;


}



//receive data from tcp transfer
void MainWindow::TCP_response_to_set(Tcp_packet *tcp_Packet,int socket_id) {

    QString status, error;

    //qDebug() << "Set Object: " << tcp_Packet->object;

    if (tcp_Packet->object == "Command") {

        QDomElement root = tcp_Packet->dataE.firstChildElement("Command");
        //turn on online recording to rx
        //format internal storage
        //if(root.firstChildElement("SwitchAllLights").text().toInt() == 1){

        //}
        //
        if(!root.firstChildElement("SwitchAllLights").isNull()){
            this->SwitchAllLights(root.firstChildElement("SwitchAllLights").text().toInt());
        }

        server->format_and_send_packet("Rx", "ResponseToSet", tcp_Packet->object, "Ok", "", socket_id);
        //qDebug().noquote()<<tcp_Packet->dataE.toString();
        return;
    }


    if (tcp_Packet->object == "Settings") {

        qDebug() << "[MainWindow] Receiving settings from web";
        status = "Ok";
        error = "";
        if(settings->set_config(tcp_Packet)){
            status = "error";
            error = "failed to save rx settings";
        }
        //respond to request
        server->format_and_send_packet("Rx", "ResponseToSet", tcp_Packet->object, status, error, socket_id);

        //qDebug().noquote()<<tcp_Packet->dataE.toString();
        return;

    }



    if (tcp_Packet->object == "WebUsers") {

        //qDebug()<<tcp_Packet->dataE.toString();
        QDomElement root = tcp_Packet->dataE.firstChildElement("WebUsers");
        //turn on online recording to rx
        //power off rx
        QString webIP = root.firstChildElement("ip").text();
        bool connected = root.firstChildElement("connected").text().toInt();


        qDebug().noquote()<<"[MainWindow] Web gui user "<<webIP+(connected ? " connected":" disconnected");
        server->format_and_send_packet("Rx", "ResponseToSet", tcp_Packet->object, "Ok", "", socket_id);
        //qDebug().noquote()<<tcp_Packet->dataE.toString();
        return;
    }


  
}


void MainWindow::LoadSettings(){

    widget.settings_door_lights_checkbox->setChecked(settings->DoorLight());
    widget.settings_door_siren_checkbox->setChecked(settings->DoorSiren());
    widget.settings_pir_lcd_checkbox->setChecked(settings->PirLcd());

    int index = widget.settings_lcd_timeout_comboBox->findText(QString::number(settings->LcdTimeout()));
    if(index > 0)
        widget.settings_lcd_timeout_comboBox->setCurrentIndex(index);

    gpio->SetPirLcd(settings->PirLcd());

}

void MainWindow::on_settings_save_button_clicked(){

    settings->SetDoorLight(widget.settings_door_lights_checkbox->isChecked());
    settings->SetDoorSiren(widget.settings_door_siren_checkbox->isChecked());
    settings->SetPirLcd(widget.settings_pir_lcd_checkbox->isChecked());

    settings->SetLcdTimeout(widget.settings_lcd_timeout_comboBox->currentText().toInt());

    settings->save_config();
    this->LoadSettings();

}

void MainWindow::SwitchAllLights(bool enable){

    QString on = enable ? "1":"0";

    corridor->send_tcp_cmd("J"+on);
    livingroom->send_tcp_cmd("J"+on);
    bedroom->send_tcp_cmd("J"+on);
    bathroom->send_tcp_cmd("J"+on);
    workroom->send_tcp_cmd("J"+on);

}
