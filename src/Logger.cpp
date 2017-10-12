
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "Config.h"



void Logger::log(int type, QString text){

    switch(type){

        case LOG_TRIGGERS: 
            {
                QFile file("./triggers.log");
                file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
                QTextStream stream(&file);
                stream<<QDateTime::currentDateTime().toString(DATE_TIME_FORMAT)<<" "<<text<<endl;
                file.close();
                break;
            }

    }


}


