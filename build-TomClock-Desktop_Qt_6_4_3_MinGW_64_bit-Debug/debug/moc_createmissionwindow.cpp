/****************************************************************************
** Meta object code from reading C++ file 'createmissionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../TomClock_QtCreator/src/createmissionwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createmissionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_CreateMissionWindow_t {
    uint offsetsAndSizes[10];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CreateMissionWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CreateMissionWindow_t qt_meta_stringdata_CreateMissionWindow = {
    {
        QT_MOC_LITERAL(0, 19),  // "CreateMissionWindow"
        QT_MOC_LITERAL(20, 12),  // "MaintoCreate"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 17),  // "on_cancel_clicked"
        QT_MOC_LITERAL(52, 18)   // "on_comfirm_clicked"
    },
    "CreateMissionWindow",
    "MaintoCreate",
    "",
    "on_cancel_clicked",
    "on_comfirm_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CreateMissionWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CreateMissionWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CreateMissionWindow.offsetsAndSizes,
    qt_meta_data_CreateMissionWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CreateMissionWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CreateMissionWindow, std::true_type>,
        // method 'MaintoCreate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_comfirm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CreateMissionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateMissionWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->MaintoCreate(); break;
        case 1: _t->on_cancel_clicked(); break;
        case 2: _t->on_comfirm_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CreateMissionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateMissionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateMissionWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CreateMissionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
