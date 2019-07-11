/****************************************************************************
** Meta object code from reading C++ file 'snakewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../xin/snakewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'snakewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_snakeWidget_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_snakeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_snakeWidget_t qt_meta_stringdata_snakeWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "snakeWidget"
QT_MOC_LITERAL(1, 12, 13), // "leftbtn_click"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "rightbtn_click"
QT_MOC_LITERAL(4, 42, 11), // "upbtn_click"
QT_MOC_LITERAL(5, 54, 13), // "downbtn_click"
QT_MOC_LITERAL(6, 68, 14), // "startbtn_click"
QT_MOC_LITERAL(7, 83, 15), // "returnbtn_click"
QT_MOC_LITERAL(8, 99, 11) // "timeoutslot"

    },
    "snakeWidget\0leftbtn_click\0\0rightbtn_click\0"
    "upbtn_click\0downbtn_click\0startbtn_click\0"
    "returnbtn_click\0timeoutslot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_snakeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void snakeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        snakeWidget *_t = static_cast<snakeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->leftbtn_click(); break;
        case 1: _t->rightbtn_click(); break;
        case 2: _t->upbtn_click(); break;
        case 3: _t->downbtn_click(); break;
        case 4: _t->startbtn_click(); break;
        case 5: _t->returnbtn_click(); break;
        case 6: _t->timeoutslot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject snakeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_snakeWidget.data,
      qt_meta_data_snakeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *snakeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *snakeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_snakeWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int snakeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
