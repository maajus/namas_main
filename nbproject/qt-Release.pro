# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = namas_main
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/MainWindow.cpp src/Pinctrl.cpp src/Room_win.cpp src/TCP.cpp src/info_widget.cpp src/main.cpp
HEADERS += headers/MainWindow.h headers/Pinctrl.h headers/Room_win.h headers/TCP.h headers/info_widget.h
FORMS += info_widget.ui ui/MainWindow.ui ui/Room_win.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
