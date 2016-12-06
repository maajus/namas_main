/********************************************************************************
** Form generated from reading UI file 'info_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_WIDGET_H
#define UI_INFO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info_widget
{
public:
    QLabel *name_label;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *temp_label;
    QLabel *label_2;
    QLabel *humidity_label;

    void setupUi(QWidget *info_widget)
    {
        if (info_widget->objectName().isEmpty())
            info_widget->setObjectName(QStringLiteral("info_widget"));
        info_widget->resize(260, 160);
        name_label = new QLabel(info_widget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 10, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        name_label->setFont(font);
        name_label->setStyleSheet(QStringLiteral("color: #282828;"));
        label_3 = new QLabel(info_widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 90, 51, 51));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/bulb_off.png")));
        label_3->setScaledContents(true);
        widget = new QWidget(info_widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 60, 171, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(37, 51));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/temp.png")));
        label->setScaledContents(true);
        label->setMargin(0);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        temp_label = new QLabel(widget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        temp_label->setFont(font1);

        gridLayout->addWidget(temp_label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(37, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/humidity.png")));
        label_2->setScaledContents(true);
        label_2->setMargin(3);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        humidity_label = new QLabel(widget);
        humidity_label->setObjectName(QStringLiteral("humidity_label"));
        humidity_label->setFont(font1);

        gridLayout->addWidget(humidity_label, 1, 1, 1, 1);


        retranslateUi(info_widget);

        QMetaObject::connectSlotsByName(info_widget);
    } // setupUi

    void retranslateUi(QWidget *info_widget)
    {
        info_widget->setWindowTitle(QApplication::translate("info_widget", "info_widget", 0));
        name_label->setText(QApplication::translate("info_widget", "N/A", 0));
        label_3->setText(QString());
        label->setText(QString());
        temp_label->setText(QApplication::translate("info_widget", "N/A", 0));
        label_2->setText(QString());
        humidity_label->setText(QApplication::translate("info_widget", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class info_widget: public Ui_info_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WIDGET_H
