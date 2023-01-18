/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../USB2CAN_driver/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[16];
    char stringdata5[25];
    char stringdata6[23];
    char stringdata7[30];
    char stringdata8[35];
    char stringdata9[32];
    char stringdata10[32];
    char stringdata11[31];
    char stringdata12[23];
    char stringdata13[8];
    char stringdata14[30];
    char stringdata15[6];
    char stringdata16[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 7),  // "timeout"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 9),  // "readyRead"
        QT_MOC_LITERAL(30, 15),  // "on_dataReceived"
        QT_MOC_LITERAL(46, 24),  // "on_timeout_listSendTimer"
        QT_MOC_LITERAL(71, 22),  // "on_pushButton_released"
        QT_MOC_LITERAL(94, 29),  // "on_pushButton_SendBtn_clicked"
        QT_MOC_LITERAL(124, 34),  // "on_pushButton_ListSendBtn_rel..."
        QT_MOC_LITERAL(159, 31),  // "on_pushButton_RX_clean_released"
        QT_MOC_LITERAL(191, 31),  // "on_pushButton_TX_clean_released"
        QT_MOC_LITERAL(223, 30),  // "on_pushButton_showDev_released"
        QT_MOC_LITERAL(254, 22),  // "on_radioButton_toggled"
        QT_MOC_LITERAL(277, 7),  // "checked"
        QT_MOC_LITERAL(285, 29),  // "on_dial_position_valueChanged"
        QT_MOC_LITERAL(315, 5),  // "value"
        QT_MOC_LITERAL(321, 24)   // "on_pushButton_2_released"
    },
    "MainWindow",
    "timeout",
    "",
    "readyRead",
    "on_dataReceived",
    "on_timeout_listSendTimer",
    "on_pushButton_released",
    "on_pushButton_SendBtn_clicked",
    "on_pushButton_ListSendBtn_released",
    "on_pushButton_RX_clean_released",
    "on_pushButton_TX_clean_released",
    "on_pushButton_showDev_released",
    "on_radioButton_toggled",
    "checked",
    "on_dial_position_valueChanged",
    "value",
    "on_pushButton_2_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,
       3,    0,   99,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,  100,    2, 0x08,    3 /* Private */,
       4,    1,  103,    2, 0x08,    5 /* Private */,
       5,    0,  106,    2, 0x08,    7 /* Private */,
       6,    0,  107,    2, 0x08,    8 /* Private */,
       7,    0,  108,    2, 0x08,    9 /* Private */,
       8,    0,  109,    2, 0x08,   10 /* Private */,
       9,    0,  110,    2, 0x08,   11 /* Private */,
      10,    0,  111,    2, 0x08,   12 /* Private */,
      11,    0,  112,    2, 0x08,   13 /* Private */,
      12,    1,  113,    2, 0x08,   14 /* Private */,
      14,    1,  116,    2, 0x08,   16 /* Private */,
      16,    0,  119,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->readyRead(); break;
        case 2: _t->on_dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->on_dataReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_timeout_listSendTimer(); break;
        case 5: _t->on_pushButton_released(); break;
        case 6: _t->on_pushButton_SendBtn_clicked(); break;
        case 7: _t->on_pushButton_ListSendBtn_released(); break;
        case 8: _t->on_pushButton_RX_clean_released(); break;
        case 9: _t->on_pushButton_TX_clean_released(); break;
        case 10: _t->on_pushButton_showDev_released(); break;
        case 11: _t->on_radioButton_toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->on_dial_position_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_pushButton_2_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::timeout; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::readyRead; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
