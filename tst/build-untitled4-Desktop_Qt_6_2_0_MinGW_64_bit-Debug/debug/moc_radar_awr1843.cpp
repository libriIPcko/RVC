/****************************************************************************
** Meta object code from reading C++ file 'radar_awr1843.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../radar_awr1843.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radar_awr1843.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RADAR_AWR1843_t {
    const uint offsetsAndSize[22];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_RADAR_AWR1843_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_RADAR_AWR1843_t qt_meta_stringdata_RADAR_AWR1843 = {
    {
QT_MOC_LITERAL(0, 13), // "RADAR_AWR1843"
QT_MOC_LITERAL(14, 7), // "timeout"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 9), // "readyRead"
QT_MOC_LITERAL(33, 20), // "Interrupt_ReadPacket"
QT_MOC_LITERAL(54, 4), // "data"
QT_MOC_LITERAL(59, 11), // "dataCounter"
QT_MOC_LITERAL(71, 17), // "port_COMM_receive"
QT_MOC_LITERAL(89, 22), // "port_AUXILIARY_receive"
QT_MOC_LITERAL(112, 17), // "tim_debug_handler"
QT_MOC_LITERAL(130, 19) // "watchdog_RX_handler"

    },
    "RADAR_AWR1843\0timeout\0\0readyRead\0"
    "Interrupt_ReadPacket\0data\0dataCounter\0"
    "port_COMM_receive\0port_AUXILIARY_receive\0"
    "tim_debug_handler\0watchdog_RX_handler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RADAR_AWR1843[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    2,   58,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   63,    2, 0x0a,    6 /* Public */,
       8,    0,   64,    2, 0x0a,    7 /* Public */,
       9,    0,   65,    2, 0x0a,    8 /* Public */,
      10,    0,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RADAR_AWR1843::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RADAR_AWR1843 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->readyRead(); break;
        case 2: _t->Interrupt_ReadPacket((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: { int _r = _t->port_COMM_receive();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->port_AUXILIARY_receive();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->tim_debug_handler(); break;
        case 6: _t->watchdog_RX_handler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RADAR_AWR1843::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RADAR_AWR1843::timeout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RADAR_AWR1843::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RADAR_AWR1843::readyRead)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RADAR_AWR1843::*)(QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RADAR_AWR1843::Interrupt_ReadPacket)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject RADAR_AWR1843::staticMetaObject = { {
    QMetaObject::SuperData::link<QSerialPort::staticMetaObject>(),
    qt_meta_stringdata_RADAR_AWR1843.offsetsAndSize,
    qt_meta_data_RADAR_AWR1843,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RADAR_AWR1843_t
, QtPrivate::TypeAndForceComplete<RADAR_AWR1843, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RADAR_AWR1843::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RADAR_AWR1843::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RADAR_AWR1843.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QThread"))
        return static_cast< QThread*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int RADAR_AWR1843::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RADAR_AWR1843::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RADAR_AWR1843::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RADAR_AWR1843::Interrupt_ReadPacket(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
