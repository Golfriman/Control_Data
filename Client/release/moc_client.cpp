/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    const uint offsetsAndSize[54];
    char stringdata0[392];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 6), // "Client"
QT_MOC_LITERAL(7, 19), // "signalAuthorization"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 12), // "QDataStream&"
QT_MOC_LITERAL(41, 14), // "signalMainMenu"
QT_MOC_LITERAL(56, 14), // "signalEmployee"
QT_MOC_LITERAL(71, 11), // "signalRooms"
QT_MOC_LITERAL(83, 13), // "signalCheckIn"
QT_MOC_LITERAL(97, 13), // "signalBooking"
QT_MOC_LITERAL(111, 12), // "signalSignUp"
QT_MOC_LITERAL(124, 12), // "signalReport"
QT_MOC_LITERAL(137, 14), // "signalSettings"
QT_MOC_LITERAL(152, 10), // "signalExit"
QT_MOC_LITERAL(163, 23), // "signalFormAuthorization"
QT_MOC_LITERAL(187, 14), // "signalFormMenu"
QT_MOC_LITERAL(202, 13), // "slotReadyRead"
QT_MOC_LITERAL(216, 12), // "sendToServer"
QT_MOC_LITERAL(229, 11), // "QByteArray&"
QT_MOC_LITERAL(241, 9), // "slotLogin"
QT_MOC_LITERAL(251, 12), // "slotShowHide"
QT_MOC_LITERAL(264, 8), // "slotQuit"
QT_MOC_LITERAL(273, 13), // "iconActivated"
QT_MOC_LITERAL(287, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(321, 6), // "reason"
QT_MOC_LITERAL(328, 18), // "disconnectToServer"
QT_MOC_LITERAL(347, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(376, 15) // "connectToServer"

    },
    "Client\0signalAuthorization\0\0QDataStream&\0"
    "signalMainMenu\0signalEmployee\0signalRooms\0"
    "signalCheckIn\0signalBooking\0signalSignUp\0"
    "signalReport\0signalSettings\0signalExit\0"
    "signalFormAuthorization\0signalFormMenu\0"
    "slotReadyRead\0sendToServer\0QByteArray&\0"
    "slotLogin\0slotShowHide\0slotQuit\0"
    "iconActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0disconnectToServer\0"
    "QAbstractSocket::SocketError\0"
    "connectToServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,
       4,    1,  137,    2, 0x06,    3 /* Public */,
       5,    1,  140,    2, 0x06,    5 /* Public */,
       6,    1,  143,    2, 0x06,    7 /* Public */,
       7,    1,  146,    2, 0x06,    9 /* Public */,
       8,    1,  149,    2, 0x06,   11 /* Public */,
       9,    1,  152,    2, 0x06,   13 /* Public */,
      10,    1,  155,    2, 0x06,   15 /* Public */,
      11,    1,  158,    2, 0x06,   17 /* Public */,
      12,    1,  161,    2, 0x06,   19 /* Public */,
      13,    2,  164,    2, 0x06,   21 /* Public */,
      14,    2,  169,    2, 0x06,   24 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  174,    2, 0x0a,   27 /* Public */,
      16,    1,  175,    2, 0x0a,   28 /* Public */,
      18,    2,  178,    2, 0x0a,   30 /* Public */,
      19,    0,  183,    2, 0x0a,   33 /* Public */,
      20,    0,  184,    2, 0x0a,   34 /* Public */,
      21,    1,  185,    2, 0x0a,   35 /* Public */,
      24,    1,  188,    2, 0x08,   37 /* Private */,
      26,    0,  191,    2, 0x08,   39 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,    2,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAuthorization((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 1: _t->signalMainMenu((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 2: _t->signalEmployee((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 3: _t->signalRooms((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 4: _t->signalCheckIn((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 5: _t->signalBooking((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 6: _t->signalSignUp((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 7: _t->signalReport((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 8: _t->signalSettings((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 9: _t->signalExit((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 10: _t->signalFormAuthorization((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->signalFormMenu((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->slotReadyRead(); break;
        case 13: _t->sendToServer((*reinterpret_cast< std::add_pointer_t<QByteArray&>>(_a[1]))); break;
        case 14: _t->slotLogin((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->slotShowHide(); break;
        case 16: _t->slotQuit(); break;
        case 17: _t->iconActivated((*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::ActivationReason>>(_a[1]))); break;
        case 18: _t->disconnectToServer((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 19: _t->connectToServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalAuthorization)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalMainMenu)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalEmployee)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalRooms)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalCheckIn)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalBooking)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalSignUp)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalReport)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalSettings)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Client::*)(QDataStream & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalExit)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Client::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalFormAuthorization)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Client::*)(bool , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signalFormMenu)) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Client.offsetsAndSize,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Client_t
, QtPrivate::TypeAndForceComplete<Client, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSystemTrayIcon::ActivationReason, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Client::signalAuthorization(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::signalMainMenu(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::signalEmployee(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::signalRooms(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::signalCheckIn(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::signalBooking(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Client::signalSignUp(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Client::signalReport(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Client::signalSettings(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Client::signalExit(QDataStream & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Client::signalFormAuthorization(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Client::signalFormMenu(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
