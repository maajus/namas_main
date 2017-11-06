
#ifndef _BLANK_WIDGET_H
#define _BLANK_WIDGET_H
#include "ui_Blank_widget.h"
#include <QObject>
#include <QDialog>

class Blank_widget : public QDialog {
    Q_OBJECT
public:

    Blank_widget();

private:
Ui_Blank_widget widget;


};
#endif
