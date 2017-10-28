######################################################################
# Automatically generated by qmake (3.0) tr lapkr. 2 19:36:35 2016
######################################################################

QT = core gui widgets network multimedia  multimediawidgets
CONFIG += silent
TEMPLATE = app
TARGET = build/namas_main
INCLUDEPATH += . src/ include/ ui/ 



# Input
HEADERS += include/build_number.h \
           include/info_widget.h \
           include/MainWindow.h \
           include/Pinctrl.h \
           include/Bath_Room_win.h \
           include/Bed_Room_win.h \
           include/Living_Room_win.h \
           include/Work_Room_win.h \
           include/Corridor_win.h \
           include/TCP.h \
           include/Camera.h \
           include/Room.h \
           include/Alarm.h \
           include/GPIO.h \
           include/Logger.h \

FORMS += ui/info_widget.ui \
            ui/MainWindow.ui \
            ui/Bath_Room_win.ui \
            ui/Bed_Room_win.ui \
            ui/Living_Room_win.ui \
            ui/Corridor_win.ui \
            ui/Work_Room_win.ui

SOURCES += src/info_widget.cpp \
           src/main.cpp \
           src/MainWindow.cpp \
           src/Bath_Room_win.cpp \
           src/Bed_Room_win.cpp \
           src/Living_Room_win.cpp \
           src/Work_Room_win.cpp \
           src/Corridor_win.cpp \
           src/TCP.cpp \
           src/Room.cpp \
           src/Alarm.cpp \
           src/GPIO.cpp \
           src/Logger.cpp \
           src/Camera.cpp

RESOURCES += resources/res.qrc

# So wiringPi include files can be found during compile
INCLUDEPATH    += ./lib


UI_DIR=ui
MOC_DIR=moc
OBJECTS_DIR=obj
RCC_DIR=rcc
UI_HEADERS_DIR=ui




contains( CONFIG, PC ) {
    message( "Configuring for PC build..." )
    INCLUDEPATH += /usr/local/include
    DEFINES += PC
    SOURCES -= src/GPIO.cpp
    HEADERS -= include/GPIO.h


}else{
    message( "Configuring for RPI build..." )
    INCLUDEPATH += /home/justas/sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi/usr/include
    QMAKE_POST_LINK += ./cp.sh
    # To link the wiringPi library when making the executable
    LIBS += -L./lib -lwiringPi
    
}
