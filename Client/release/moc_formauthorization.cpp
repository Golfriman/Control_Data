/****************************************************************************
** Meta object code from reading C++ file 'formauthorization.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Form Authorization/formauthorization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formauthorization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormAuthorization_t {
    const uint offsetsAndSize[30];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FormAuthorization_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FormAuthorization_t qt_meta_stringdata_FormAuthorization = {
    {
QT_MOC_LITERAL(0, 17), // "FormAuthorization"
QT_MOC_LITERAL(18, 7), // "request"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 11), // "QByteArray&"
QT_MOC_LITERAL(39, 5), // "login"
QT_MOC_LITERAL(45, 6), // "update"
QT_MOC_LITERAL(52, 12), // "QDataStream&"
QT_MOC_LITERAL(65, 2), // "in"
QT_MOC_LITERAL(68, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(90, 21), // "on_pushButton_pressed"
QT_MOC_LITERAL(112, 22), // "on_pushButton_released"
QT_MOC_LITERAL(135, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(160, 4), // "arg1"
QT_MOC_LITERAL(165, 25), // "on_password_returnPressed"
QT_MOC_LITERAL(191, 21) // "on_quitButton_clicked"

    },
    "FormAuthorization\0request\0\0QByteArray&\0"
    "login\0update\0QDataStream&\0in\0"
    "on_pushButton_clicked\0on_pushButton_pressed\0"
    "on_pushButton_released\0on_checkBox_stateChanged\0"
    "arg1\0on_password_returnPressed\0"
    "on_quitButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormAuthorization[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    1 /* Public */,
       4,    2,   71,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   76,    2, 0x0a,    6 /* Public */,
       8,    0,   79,    2, 0x08,    8 /* Private */,
       9,    0,   80,    2, 0x08,    9 /* Private */,
      10,    0,   81,    2, 0x08,   10 /* Private */,
      11,    1,   82,    2, 0x08,   11 /* Private */,
      13,    0,   85,    2, 0x08,   13 /* Private */,
      14,    0,   86,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormAuthorization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormAuthorization *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->request((*reinterpret_cast< std::add_pointer_t<QByteArray&>>(_a[1]))); break;
        case 1: _t->login((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->update((*reinterpret_cast< std::add_pointer_t<QDataStream&>>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_pressed(); break;
        case 5: _t->on_pushButton_released(); break;
        case 6: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_password_returnPressed(); break;
        case 8: _t->on_quitButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormAuthorization::*)(QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAuthorization::request)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FormAuthorization::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormAuthorization::login)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FormAuthorization::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_FormAuthorization.offsetsAndSize,
    qt_meta_data_FormAuthorization,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FormAuthorization_t
, QtPrivate::TypeAndForceComplete<FormAuthorization, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QDataStream &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FormAuthorization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormAuthorization::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormAuthorization.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FormAuthorization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FormAuthorization::request(QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FormAuthorization::login(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
