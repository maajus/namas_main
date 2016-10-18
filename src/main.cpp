/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: justas
 *
 * Created on August 6, 2016, 1:22 PM
 */

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    QApplication::setStyle("fusion");

    // create and show your widgets here
    MainWindow w;
    w.show();
    return app.exec();
}
