#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "TCP.h"
#include "DataLogger.h"
#include <QDomDocument>

class Room : public QObject
{

    Q_OBJECT

    public:
        Room (ROOM_ID);
        QString read_ip();
        void sendData(QByteArray);
        void switch_all_lights(bool);
        void toggle_all_lights();
        void status2xml(QDomDocument *root);

    private:
        QString ip;
        TCP *tcp;
        Room_status status;
        int connection_status;
        QTimer *reconnect_timer;
        ROOM_ID room_id;
        DataLogger *logger;

        private slots:
            void tcp_data(QByteArray data);
        void set_connection_status(int);
        void connect2module();

signals:
        void room_status_received(Room_status);
};




#endif // ifndef ROOM_H


