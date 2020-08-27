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
#include "build_number.h"

MainWindow::MainWindow() {

    gpio = new GPIO();
    connect(gpio, &GPIO::gpio_interrupt, this, &MainWindow::gpio_interrupt);
    ws_server = new WSserver(5050);
    settings = new Settings();
    widget.setupUi(this);


    connect(ws_server, SIGNAL(json_received(QWebSocket*, nlohmann::json)), this, SLOT(WS_dataReceived(QWebSocket*, nlohmann::json)));

    connect(&status_timer, SIGNAL(timeout()), this, SLOT(update_status()));
    connect(&info_timer, SIGNAL(timeout()), this, SLOT(update_info()));
    connect(widget.side_menu,SIGNAL(currentRowChanged(int)),SLOT(menu_selected(int)));

    status_timer.start(STATUS_REFRESH);
    info_timer.start(ROOM_INFO_UPDATE_FREQ);

    bathroom = new Room(ROOM_ID::BATHROOM);
    bedroom = new Room(ROOM_ID::BEDROOM);
    workroom = new Room(ROOM_ID::WORKROOM);
    corridor = new Room(ROOM_ID::CORRIDOR);
    livingroom = new Room(ROOM_ID::LIVING_ROOM);

    qApp->installEventFilter(this); //install event filter to catch mouse events

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

    qDebug()<<"Build nr"<<BUILD;

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
}


void MainWindow::gpio_interrupt(int intnr){

    switch(intnr){
        case INT_DOOR_OPEN:
            {
                Logger::log(LOG_TRIGGERS, "Door opened");
                //if pir = 0 door should be opened from outside
                if(gpio->read(GPIO_PIR) == 0){
                    if(settings->DoorLight()) corridor->sendData("L2");
                    if(settings->DoorSiren())  gpio->siren_beep();
                }
                else{ //door opened from inside
                    if(settings->DoorLight()){
                        if(corridor->get_status().L[2] == 1) //if corridor lights if on turn them off
                            corridor->sendData("L2");
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

enum{
    CMD_NONE = 0,
    CMD_GET_STATUS = 1,
    CMD_SET_OUTPUT = 2,
};


void MainWindow::WS_dataReceived(QWebSocket *pClient, nlohmann::json j){

    //nlohmann::json j_out;
    int cmdID;

    try{
        cmdID = j["cmdID"];
        //cmd.args = j["args"].get<std::vector<std::string>>(); //get args array
    }
    catch (const std::exception&) {
        qDebug() << "[MainWindow] Failed to parse json ";
        return;
    }

    switch(cmdID){
        case CMD_SET_OUTPUT:
            {
                int room_id = j["room_id"];
                int light_id = j["idx"];

                switch(room_id){
                    case LIVING_ROOM:
                    livingroom->toggle_light(light_id);
                    break;

                    case BEDROOM:
                    bedroom->toggle_light(light_id);
                    break;

                    case WORKROOM:
                    workroom->toggle_light(light_id);
                    break;

                    case CORRIDOR:
                    corridor->toggle_light(light_id);
                    break;

                    case BATHROOM:
                    bathroom->toggle_light(light_id);
                    break;

                }
                break;
            }

        case CMD_GET_STATUS:
            {
                nlohmann::json j;
                nlohmann::json j_out = nlohmann::json::array();

                j_out.push_back(bedroom->status2json());
                j_out.push_back(livingroom->status2json());
                j_out.push_back(bathroom->status2json());
                j_out.push_back(corridor->status2json());
                j_out.push_back(workroom->status2json());
                j["door_pir"] = gpio->read(GPIO_PIR);
                j["rooms"] = j_out;
                ws_server->sendJson(pClient, j);

                break;
            }
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

    corridor->sendData("J"+on);
    livingroom->sendData("J"+on);
    bedroom->sendData("J"+on);
    bathroom->sendData("J"+on);
    workroom->sendData("J"+on);

}
