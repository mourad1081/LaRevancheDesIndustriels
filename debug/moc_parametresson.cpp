/****************************************************************************
** Meta object code from reading C++ file 'parametresson.h'
**
<<<<<<< HEAD
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
=======
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
>>>>>>> 4df10b7b27182451eb9782806effc8fca94a103e
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vue/parametresson.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametresson.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
<<<<<<< HEAD
#error "This file was generated using the moc from 5.2.1. It"
=======
#error "This file was generated using the moc from 5.1.1. It"
>>>>>>> 4df10b7b27182451eb9782806effc8fca94a103e
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParametresSon_t {
    QByteArrayData data[1];
    char stringdata[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ParametresSon_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ParametresSon_t qt_meta_stringdata_ParametresSon = {
    {
QT_MOC_LITERAL(0, 0, 13)
    },
    "ParametresSon\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParametresSon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ParametresSon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ParametresSon::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParametresSon.data,
      qt_meta_data_ParametresSon,  qt_static_metacall, 0, 0}
};


const QMetaObject *ParametresSon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParametresSon::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParametresSon.stringdata))
        return static_cast<void*>(const_cast< ParametresSon*>(this));
    return QDialog::qt_metacast(_clname);
}

int ParametresSon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
