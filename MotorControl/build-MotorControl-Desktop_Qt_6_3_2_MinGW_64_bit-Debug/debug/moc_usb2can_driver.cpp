/****************************************************************************
** Meta object code from reading C++ file 'usb2can_driver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../USB2CAN_driver/usb2can_driver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usb2can_driver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_USB2CAN_driver_t {
    uint offsetsAndSizes[20];
    char stringdata0[15];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[13];
    char stringdata5[9];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[16];
    char stringdata9[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_USB2CAN_driver_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_USB2CAN_driver_t qt_meta_stringdata_USB2CAN_driver = {
    {
        QT_MOC_LITERAL(0, 14),  // "USB2CAN_driver"
        QT_MOC_LITERAL(15, 7),  // "timeout"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 12),  // "dataReceived"
        QT_MOC_LITERAL(37, 12),  // "read_USB2CAN"
        QT_MOC_LITERAL(50, 8),  // "initSend"
        QT_MOC_LITERAL(59, 10),  // "initSend_1"
        QT_MOC_LITERAL(70, 10),  // "deinitSend"
        QT_MOC_LITERAL(81, 15),  // "listCANmsg_slot"
        QT_MOC_LITERAL(97, 4)   // "list"
    },
    "USB2CAN_driver",
    "timeout",
    "",
    "dataReceived",
    "read_USB2CAN",
    "initSend",
    "initSend_1",
    "deinitSend",
    "listCANmsg_slot",
    "list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_USB2CAN_driver[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    1,   63,    2, 0x06,    2 /* Public */,
       3,    1,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   69,    2, 0x08,    6 /* Private */,
       5,    0,   70,    2, 0x08,    7 /* Private */,
       6,    0,   71,    2, 0x08,    8 /* Private */,
       7,    0,   72,    2, 0x08,    9 /* Private */,
       8,    1,   73,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::QByteArray,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Int, QMetaType::QStringList,    9,

       0        // eod
};

void USB2CAN_driver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<USB2CAN_driver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 2: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QByteArray _r = _t->read_USB2CAN();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->initSend();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->initSend_1(); break;
        case 6: { bool _r = _t->deinitSend();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->listCANmsg_slot((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (USB2CAN_driver::*)();
            if (_t _q_method = &USB2CAN_driver::timeout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (USB2CAN_driver::*)(QByteArray );
            if (_t _q_method = &USB2CAN_driver::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (USB2CAN_driver::*)(QString );
            if (_t _q_method = &USB2CAN_driver::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject USB2CAN_driver::staticMetaObject = { {
    QMetaObject::SuperData::link<QSerialPort::staticMetaObject>(),
    qt_meta_stringdata_USB2CAN_driver.offsetsAndSizes,
    qt_meta_data_USB2CAN_driver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_USB2CAN_driver_t
, QtPrivate::TypeAndForceComplete<USB2CAN_driver, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList, std::false_type>


>,
    nullptr
} };


const QMetaObject *USB2CAN_driver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *USB2CAN_driver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_USB2CAN_driver.stringdata0))
        return static_cast<void*>(this);
    return QSerialPort::qt_metacast(_clname);
}

int USB2CAN_driver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void USB2CAN_driver::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void USB2CAN_driver::dataReceived(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void USB2CAN_driver::dataReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
