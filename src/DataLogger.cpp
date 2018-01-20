#include "DataLogger.h"
#include <QObject>
#include <QDateTime>
#include "Config.h"

DataLogger::DataLogger(ROOM_ID id) {

    room_id = id;
    connect(&timer, SIGNAL(timeout()), this, SLOT(WriteData()));
    timer.start(DATALOG_PERIOD * 60000);
    first_data = true;
}

void DataLogger::data(Room_status Status){

    status = Status;
    if(first_data){
        this->WriteData();
        first_data = false;
    }
}

void DataLogger::WriteData(){

    QString filename;

    switch (room_id){
    case BATHROOM:
        filename = "Vonia.log";
        break;
    case CORRIDOR:
        filename = "Koridorius.log";
        break;
    case BEDROOM:
        filename = "Miegamasis.log";
        break;
    case WORKROOM:
        filename = "VaikuKambarys.log";
        break;
    case LIVING_ROOM:
        filename = "Svetaine.log";
        break;
    default:
        qDebug()<<"[DataLogger] No such room id "<<room_id;
        return;
    }

    QFile file(LOG_DIR + filename);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append)){
        qDebug()<<"[DataLogger] Failed to open"<<filename;
        return;
    }

    QTextStream stream(&file);
    stream<<QDateTime::currentDateTime().toString(DATE_TIME_FORMAT)
        <<" T"<<status.temp<<" H"<<status.humi
        <<endl;

    file.close();

}
