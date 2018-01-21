#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <QDomDocument>
#include "tcp_server.h"

class Settings{

    public:
        Settings();
        int read_config();
        int save_config();
        int get_config(Tcp_packet * packet);
        int set_config(Tcp_packet * packet);
        void load_settings();

        void SetLcdTimeout(int);
        void SetPirLcd(bool);
        void SetDoorLight(bool);
        void SetDoorSiren(bool);


        int LcdTimeout();
        bool DoorLight();
        bool DoorSiren();
        bool PirLcd();

    private:
        int xml_to_file(QDomDocument *domdoc);
        void config_to_xml(QDomDocument *domdoc);
        int xml_to_config(QDomDocument *domdoc);

        int lcd_timeout;
        bool door_light;
        bool door_siren;
        bool pir_lcd;

};

#endif
