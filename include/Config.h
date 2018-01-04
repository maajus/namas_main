#ifndef CONFIG_H
#define CONFIG_H

#define DATE_TIME_FORMAT "yyyy_MM_dd_hh:mm:ss"

//GPIO
#define GPIO_PIR 4 //geltonas laidas RPI
#define GPIO_SIREN 1 //baltas laidas RPI
#define GPIO_REED 7 //melynas laidas RPI
#define GPIO_LCD_BL 11

#define STATUS_REFRESH 1500
#define ROOM_INFO_UPDATE_FREQ 5000


//ip adress
#define IP_VONIA "192.168.1.236"
#define IP_SVETAINE "192.168.1.100"
#define IP_KORIDORIUS "192.168.1.237"
#define IP_MIEGAMASIS "192.168.1.200"
#define IP_VAIKUKAMBARYS "192.168.1.150"


#endif
