
#ifndef _LOGGER_H
#define _LOGGER_H

#include <QString>

enum LOG_TYPE {
    LOG_TRIGGERS,
};

class Logger {

public:
    Logger();
    static void log(int type, QString text);

private:



};



#endif
