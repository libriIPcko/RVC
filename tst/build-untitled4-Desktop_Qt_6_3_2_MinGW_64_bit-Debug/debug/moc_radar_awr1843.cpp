/****************************************************************************
** Meta object code from reading C++ file 'radar_awr1843.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
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
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RADAR_AWR1843_t {
    uint offsetsAndSizes[28];
    char stringdata0[14];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[21];
    char stringdata5[5];
    char stringdata6[12];
    char stringdata7[26];
    char stringdata8[8];
    char stringdata9[12];
    char stringdata10[18];
    char stringdata11[23];
    char stringdata12[18];
    char stringdata13[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RADAR_AWR1843_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_RADAR_AWR1843_t qt_meta_stringdata_RADAR_AWR1843 = {
    {
        QT_MOC_LITERAL(0, 13),  // "RADAR_AWR1843"
        QT_MOC_LITERAL(14, 7),  // "timeout"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 9),  // "readyRead"
        QT_MOC_LITERAL(33, 20),  // "Interrupt_ReadPacket"
        QT_MOC_LITERAL(54, 4),  // "data"
        QT_MOC_LITERAL(59, 11),  // "dataCounter"
        QT_MOC_LITERAL(71, 25),  // "Interrupt_ReadTLV_packets"
        QT_MOC_LITERAL(97, 7),  // "TLV_dat"
        QT_MOC_LITERAL(105, 11),  // "TLV_packets"
        QT_MOC_LITERAL(117, 17),  // "port_COMM_receive"
        QT_MOC_LITERAL(135, 22),  // "port_AUXILIARY_receive"
        QT_MOC_LITERAL(158, 17),  // "tim_debug_handler"
        QT_MOC_LITERAL(176, 19)   // "watchdog_RX_handler"
    },
    "RADAR_AWR1843",
    "timeout",
    "",
    "readyRead",
    "Interrupt_ReadPacket",
    "data",
    "dataCounter",
    "Interrupt_ReadTLV_packets",
    "TLV_dat",
    "TLV_packets",
    "port_COMM_receive",
    "port_AUXILIARY_receive",
    "tim_debug_handler",
    "watchdog_RX_handler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RADAR_AWR1843[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    2,   64,    2, 0x06,    3 /* Public */,
       7,    1,   69,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   72,    2, 0x0a,    8 /* Public */,
      11,    0,   73,    2, 0x0a,    9 /* Public */,
      12,    0,   74,    2, 0x0a,   10 /* Public */,
      13,    0,   75,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,

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
        case 2: _t->Interrupt_ReadPacket((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->Interrupt_ReadTLV_packets((*reinterpret_cast< std::add_pointer_t<TLV_dat>>(_a[1]))); break;
        case 4: { int _r = _t->port_COMM_receive();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { int _r = _t->port_AUXILIARY_receive();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->tim_debug_handler(); break;
        case 7: _t->watchdog_RX_handler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RADAR_AWR1843::*)();
            if (_t _q_method = &RADAR_AWR1843::timeout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RADAR_AWR1843::*)();
            if (_t _q_method = &RADAR_AWR1843::readyRead; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RADAR_AWR1843::*)(QString , int );
            if (_t _q_method = &RADAR_AWR1843::Interrupt_ReadPacket; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RADAR_AWR1843::*)(TLV_dat );
            if (_t _q_method = &RADAR_AWR1843::Interrupt_ReadTLV_packets; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RADAR_AWR1843::staticMetaObject = { {
    QMetaObject::SuperData::link<QSerialPort::staticMetaObject>(),
    qt_meta_stringdata_RADAR_AWR1843.offsetsAndSizes,
    qt_meta_data_RADAR_AWR1843,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RADAR_AWR1843_t
, QtPrivate::TypeAndForceComplete<RADAR_AWR1843, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TLV_dat, std::false_type>
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
    return QSerialPort::qt_metacast(_clname);
}

int RADAR_AWR1843::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
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

// SIGNAL 3
void RADAR_AWR1843::Interrupt_ReadTLV_packets(TLV_dat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
