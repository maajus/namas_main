#include "Settings.h"
#include <QFile>
#include <QMutex>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include "Config.h"
//#include "Version.h"
//#include "UserManager.h"

QMutex mutex;


Settings::Settings(){

    lcd_timeout = 30;
    door_light = false;
    door_light = false;
    pir_lcd = false;
    this->read_config();
}


//write xml to file

int Settings::save_config() {

    QDomDocument domdoc;
    this->config_to_xml(&domdoc);
    this->xml_to_file(&domdoc);
    return 0;

}

int Settings::xml_to_file(QDomDocument *domdoc) {

    QFile file;

    mutex.lock();
    file.setFileName(CONFIG_DIR"settings.xml");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "[Settings] Failed to open settings.xml";
        mutex.unlock();
        return 1;
    }

    file.seek(0);
    file.resize(0);
    QTextStream stream(&file);
    stream << domdoc->toString();

    file.close();
    mutex.unlock();

    return 0;
}


//read xml from file

int Settings::read_config() {

    QDomDocument domdoc;
    QString errorStr;
    int errorLine;
    int errorColumn;
    QFile file;

    mutex.lock();
    file.setFileName(CONFIG_DIR"settings.xml");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "[Settings] Failed to open settings.xml";
        mutex.unlock();
        return 1;
    }

    if (!domdoc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
        qDebug() << "[Settings] " << errorStr << errorLine << errorColumn;
        file.close();
        mutex.unlock();
        return 1;
    }

    this->xml_to_config(&domdoc);
    file.close();
    mutex.unlock();

    return 0;

}


void Settings::config_to_xml(QDomDocument *domdoc) {


    QDomElement root, element, temp, root1;

    root = domdoc->createElement("Settings");

    //Backlight settings
    element = domdoc->createElement("backlight_off_timeout");
    element.appendChild(domdoc->createTextNode(QString::number(lcd_timeout)));
    root.appendChild(element);


    element = domdoc->createElement("door_light");
    element.appendChild(domdoc->createTextNode(QString::number(door_light)));
    root.appendChild(element);


    element = domdoc->createElement("door_siren");
    element.appendChild(domdoc->createTextNode(QString::number(door_siren)));
    root.appendChild(element);


    element = domdoc->createElement("pir_lcd");
    element.appendChild(domdoc->createTextNode(QString::number(pir_lcd)));
    root.appendChild(element);


    ////Version
    //element = domdoc->createElement("Version");
    //element.appendChild(domdoc->createTextNode(QString(VERSION)));
    //root.appendChild(element);


    domdoc->appendChild(root);

}


int Settings::xml_to_config(QDomDocument *domdoc) {

    QDomElement root, element;

    root = domdoc->firstChildElement();
    element = root.firstChildElement("backlight_off_timeout");
    if(!element.isNull()) lcd_timeout = element.text().toInt();


    root = domdoc->firstChildElement();
    element = root.firstChildElement("pir_lcd");
    if(!element.isNull()) pir_lcd = element.text().toInt();


    root = domdoc->firstChildElement();
    element = root.firstChildElement("door_light");
    if(!element.isNull()) door_light = element.text().toInt();


    root = domdoc->firstChildElement();
    element = root.firstChildElement("door_siren");
    if(!element.isNull()) door_siren = element.text().toInt();


    return 0;
}



void Settings::load_settings(){

}

int Settings::get_config(Tcp_packet * packet) {

    if (read_config()) return 1;
    this->config_to_xml(&packet->dataE);
    //qDebug()<<packet->dataE.toString();
    return 0;
}

int Settings::set_config(Tcp_packet * packet) {

    //qDebug().noquote() << packet->dataE.toString();
    if(this->xml_to_config(&packet->dataE)){
        return 1;
    }

    QDomDocument dom;
    this->config_to_xml(&dom);
    this->xml_to_file(&dom); //write new config to file
    this->read_config(); //read new config from file
    this->load_settings();// load new config
    return 0;
}


void Settings::SetLcdTimeout(int timeout){

    if(lcd_timeout != timeout){
        lcd_timeout = timeout;
        //power_control->set_backlight_level(lcd.brightness);
    }

}

void Settings::SetDoorLight(bool enable){
    door_light = enable;
}

void Settings::SetDoorSiren(bool enable){
    door_siren = enable;
}


void Settings::SetPirLcd(bool enable){
    door_siren = enable;
}


int Settings::LcdTimeout(){
    return lcd_timeout;
}

bool Settings::DoorLight(){
    return door_light;
}

bool Settings::DoorSiren(){
    return door_siren;
}
bool Settings::PirLcd(){
    return pir_lcd;
}
