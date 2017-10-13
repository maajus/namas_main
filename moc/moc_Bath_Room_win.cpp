/****************************************************************************
** Meta object code from reading C++ file 'Bath_Room_win.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/Bath_Room_win.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Bath_Room_win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bath_Room_win_t {
    QByteArrayData data[9];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bath_Room_win_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bath_Room_win_t qt_meta_stringdata_Bath_Room_win = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Bath_Room_win"
QT_MOC_LITERAL(1, 14, 20), // "room_status_received"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "Room_status"
QT_MOC_LITERAL(4, 48, 21), // "set_connection_status"
QT_MOC_LITERAL(5, 70, 25), // "on_lights0_button_clicked"
QT_MOC_LITERAL(6, 96, 25), // "on_lights1_button_clicked"
QT_MOC_LITERAL(7, 122, 25), // "on_lights2_button_clicked"
QT_MOC_LITERAL(8, 148, 22) // "on_back_button_clicked"

    },
    "Bath_Room_win\0room_status_received\0\0"
    "Room_status\0set_connection_status\0"
    "on_lights0_button_clicked\0"
    "on_lights1_button_clicked\0"
    "on_lights2_button_clicked\0"
    "on_back_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bath_Room_win[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    0,   50,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    0,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Bath_Room_win::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bath_Room_win *_t = static_cast<Bath_Room_win *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->room_status_received((*reinterpret_cast< Room_status(*)>(_a[1]))); break;
        case 1: _t->set_connection_status((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_lights0_button_clicked(); break;
        case 3: _t->on_lights1_button_clicked(); break;
        case 4: _t->on_lights2_button_clicked(); break;
        case 5: _t->on_back_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Bath_Room_win::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Bath_Room_win.data,
      qt_meta_data_Bath_Room_win,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Bath_Room_win::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bath_Room_win::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bath_Room_win.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Bath_Room_win::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
