/****************************************************************************
** Meta object code from reading C++ file 'circuit.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Test/circuit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'circuit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Circuit_t {
    const uint offsetsAndSize[16];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Circuit_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Circuit_t qt_meta_stringdata_Circuit = {
    {
QT_MOC_LITERAL(0, 7), // "Circuit"
QT_MOC_LITERAL(8, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 12), // "QMouseEvent*"
QT_MOC_LITERAL(37, 15), // "mousePressEvent"
QT_MOC_LITERAL(53, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(71, 13), // "keyPressEvent"
QT_MOC_LITERAL(85, 10) // "QKeyEvent*"

    },
    "Circuit\0mouseMoveEvent\0\0QMouseEvent*\0"
    "mousePressEvent\0mouseReleaseEvent\0"
    "keyPressEvent\0QKeyEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Circuit[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x08,    0 /* Private */,
       4,    1,   41,    2, 0x08,    2 /* Private */,
       5,    1,   44,    2, 0x08,    4 /* Private */,
       6,    1,   47,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void Circuit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Circuit *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Circuit::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_Circuit.offsetsAndSize,
    qt_meta_data_Circuit,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Circuit_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *Circuit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Circuit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Circuit.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Circuit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
