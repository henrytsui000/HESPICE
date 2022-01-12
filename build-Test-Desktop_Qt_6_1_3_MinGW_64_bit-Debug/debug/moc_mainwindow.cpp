/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Test/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[413];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 20), // "on_actionR_triggered"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 20), // "on_actionL_triggered"
QT_MOC_LITERAL(54, 20), // "on_actionC_triggered"
QT_MOC_LITERAL(75, 20), // "on_actionV_triggered"
QT_MOC_LITERAL(96, 20), // "on_actionI_triggered"
QT_MOC_LITERAL(117, 22), // "on_actionGND_triggered"
QT_MOC_LITERAL(140, 22), // "on_actionCUT_triggered"
QT_MOC_LITERAL(163, 23), // "on_actionMOVE_triggered"
QT_MOC_LITERAL(187, 23), // "on_actionWIRE_triggered"
QT_MOC_LITERAL(211, 24), // "on_actionBUILD_triggered"
QT_MOC_LITERAL(236, 23), // "on_actionWAVE_triggered"
QT_MOC_LITERAL(260, 26), // "on_actionZOOM_IN_triggered"
QT_MOC_LITERAL(287, 27), // "on_actionZOOM_OUT_triggered"
QT_MOC_LITERAL(315, 23), // "on_actionHELP_triggered"
QT_MOC_LITERAL(339, 24), // "on_actionCLEAR_triggered"
QT_MOC_LITERAL(364, 24), // "on_actionIMAGE_triggered"
QT_MOC_LITERAL(389, 23) // "on_actionSAVE_triggered"

    },
    "MainWindow\0on_actionR_triggered\0\0"
    "on_actionL_triggered\0on_actionC_triggered\0"
    "on_actionV_triggered\0on_actionI_triggered\0"
    "on_actionGND_triggered\0on_actionCUT_triggered\0"
    "on_actionMOVE_triggered\0on_actionWIRE_triggered\0"
    "on_actionBUILD_triggered\0"
    "on_actionWAVE_triggered\0"
    "on_actionZOOM_IN_triggered\0"
    "on_actionZOOM_OUT_triggered\0"
    "on_actionHELP_triggered\0"
    "on_actionCLEAR_triggered\0"
    "on_actionIMAGE_triggered\0"
    "on_actionSAVE_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x08,    0 /* Private */,
       3,    0,  117,    2, 0x08,    1 /* Private */,
       4,    0,  118,    2, 0x08,    2 /* Private */,
       5,    0,  119,    2, 0x08,    3 /* Private */,
       6,    0,  120,    2, 0x08,    4 /* Private */,
       7,    0,  121,    2, 0x08,    5 /* Private */,
       8,    0,  122,    2, 0x08,    6 /* Private */,
       9,    0,  123,    2, 0x08,    7 /* Private */,
      10,    0,  124,    2, 0x08,    8 /* Private */,
      11,    0,  125,    2, 0x08,    9 /* Private */,
      12,    0,  126,    2, 0x08,   10 /* Private */,
      13,    0,  127,    2, 0x08,   11 /* Private */,
      14,    0,  128,    2, 0x08,   12 /* Private */,
      15,    0,  129,    2, 0x08,   13 /* Private */,
      16,    0,  130,    2, 0x08,   14 /* Private */,
      17,    0,  131,    2, 0x08,   15 /* Private */,
      18,    0,  132,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionR_triggered(); break;
        case 1: _t->on_actionL_triggered(); break;
        case 2: _t->on_actionC_triggered(); break;
        case 3: _t->on_actionV_triggered(); break;
        case 4: _t->on_actionI_triggered(); break;
        case 5: _t->on_actionGND_triggered(); break;
        case 6: _t->on_actionCUT_triggered(); break;
        case 7: _t->on_actionMOVE_triggered(); break;
        case 8: _t->on_actionWIRE_triggered(); break;
        case 9: _t->on_actionBUILD_triggered(); break;
        case 10: _t->on_actionWAVE_triggered(); break;
        case 11: _t->on_actionZOOM_IN_triggered(); break;
        case 12: _t->on_actionZOOM_OUT_triggered(); break;
        case 13: _t->on_actionHELP_triggered(); break;
        case 14: _t->on_actionCLEAR_triggered(); break;
        case 15: _t->on_actionIMAGE_triggered(); break;
        case 16: _t->on_actionSAVE_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
