/****************************************************************************
** Meta object code from reading C++ file 'Room_win.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../headers/Room_win.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Room_win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Room_win_t {
    QByteArrayData data[6];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Room_win_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Room_win_t qt_meta_stringdata_Room_win = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Room_win"
QT_MOC_LITERAL(1, 9, 7), // "cmd2EPS"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "data"
QT_MOC_LITERAL(4, 23, 25), // "on_lights1_button_clicked"
QT_MOC_LITERAL(5, 49, 22) // "on_back_button_clicked"

    },
    "Room_win\0cmd2EPS\0\0data\0on_lights1_button_clicked\0"
    "on_back_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Room_win[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Room_win::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Room_win *_t = static_cast<Room_win *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cmd2EPS((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->on_lights1_button_clicked(); break;
        case 2: _t->on_back_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Room_win::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room_win::cmd2EPS)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Room_win::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Room_win.data,
      qt_meta_data_Room_win,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Room_win::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Room_win::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Room_win.stringdata0))
        return static_cast<void*>(const_cast< Room_win*>(this));
    return QDialog::qt_metacast(_clname);
}

int Room_win::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Room_win::cmd2EPS(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
