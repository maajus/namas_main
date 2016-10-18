# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = ./
TARGET = namas
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets network
SOURCES += src/MainWindow.cpp src/Pinctrl.cpp src/Room_win.cpp src/TCP.cpp src/info_widget.cpp src/main.cpp
HEADERS += headers/MainWindow.h headers/Pinctrl.h headers/Room_win.h headers/TCP.h headers/info_widget.h
FORMS += info_widget.ui ui/MainWindow.ui ui/Room_win.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/rpi-Linux
MOC_DIR = ./moc
RCC_DIR = ./rcc
UI_DIR = ./ui
QMAKE_CC = arm-poky-linux-gnueabi-gcc
QMAKE_CXX = arm-poky-linux-gnueabi-g++
DEFINES += 
INCLUDEPATH += /mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi/usr/include /mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi/usr/include/c++/4.9.2 /mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi/usr/include/c++/4.9.2/arm-poky-linux-gnueabi headers 
LIBS += -lwiringPi  -Wl,-rpath,/mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi/usr/lib 
CXX=arm-poky-linux-gnueabi-g++  -march=armv7-a -marm  -mthumb-interwork -mfloat-abi=hard -mtune=cortex-a5 --sysroot=/mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi
CPP=arm-poky-linux-gnueabi-gcc -E  -march=armv7-a -marm  -mthumb-interwork -mfloat-abi=hard -mtune=cortex-a5 --sysroot=/mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi
QMAKE_LINK=arm-poky-linux-gnueabi-g++
QMAKE_CXXFLAGS=-march=armv6 -mfloat-abi=hard -mtune=arm1176jzf-s -mfpu=vfp
QMAKE_CFLAGS=-march=armv6 -mfloat-abi=hard -mtune=arm1176jzf-s -mfpu=vfp
QMAKE_LFLAGS=-march=armv6 -mfloat-abi=hard -mtune=arm1176jzf-s -mfpu=vfp --sysroot=/mnt/data/work/namas-sdk/sysroots/arm1176jzfshf-vfp-poky-linux-gnueabi
 PATH=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5:$PATH
 OE_QMAKE_CFLAGS=-O2 -pipe -g -feliminate-unused-debug-types
 OE_QMAKE_CXXFLAGS= -O2 -pipe -g -feliminate-unused-debug-types
 OE_QMAKE_LDFLAGS=-Wl,-O1 -Wl,--hash-style=gnu -Wl,--as-needed
 QT_CONF_PATH=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/qt.conf
 OE_QMAKE_LIBDIR_QT=`qmake -query QT_INSTALL_LIBS`
 OE_QMAKE_INCDIR_QT=`qmake -query QT_INSTALL_HEADERS`
 OE_QMAKE_MOC=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/moc
 OE_QMAKE_UIC=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/uic
 OE_QMAKE_RCC=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/rcc
 OE_QMAKE_QDBUSCPP2XML=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/qdbuscpp2xml
 OE_QMAKE_QDBUSXML2CPP=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5/qdbusxml2cpp
 OE_QMAKE_QT_CONFIG=`qmake -query QT_INSTALL_LIBS`/qt5/mkspecs/qconfig.pri
 OE_QMAKE_PATH_HOST_BINS=/mnt/data/work/namas-sdk/sysroots/x86_64-pokysdk-linux/usr/bin/qt5
 QMAKESPEC=`qmake -query QT_INSTALL_LIBS`/qt5/mkspecs/linux-oe-g++
