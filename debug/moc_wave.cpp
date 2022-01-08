/****************************************************************************
** Meta object code from reading C++ file 'wave.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Test/wave.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wave.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wave_t {
    const uint offsetsAndSize[18];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Wave_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Wave_t qt_meta_stringdata_Wave = {
    {
QT_MOC_LITERAL(0, 4), // "Wave"
QT_MOC_LITERAL(5, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 12), // "QMouseEvent*"
QT_MOC_LITERAL(34, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(56, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(80, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(104, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(136, 5) // "index"

    },
    "Wave\0mouseMoveEvent\0\0QMouseEvent*\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_comboBox_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wave[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    0 /* Private */,
       4,    0,   47,    2, 0x08,    2 /* Private */,
       5,    0,   48,    2, 0x08,    3 /* Private */,
       6,    0,   49,    2, 0x08,    4 /* Private */,
       7,    1,   50,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void Wave::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Wave *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Wave::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Wave.offsetsAndSize,
    qt_meta_data_Wave,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Wave_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Wave::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wave::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wave.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Wave::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
