#ifndef DATA_LOGGER_
#define DATA_LOGGER_

#include <QTimer>
#include "definitions.h"
#include "info_widget.h"

class DataLogger : QObject {

Q_OBJECT
    public:
        DataLogger(ROOM_ID);
        void data(Room_status);

        private slots:
            void WriteData();

    private:
        bool first_data;
        Room_status status;
        QTimer timer;
        ROOM_ID room_id;

};

#endif
