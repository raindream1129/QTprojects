/****************************************************************************
** Meta object code from reading C++ file 'readhstdt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Fio188Tools/readhstdt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readhstdt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ReadHstDt_t {
    QByteArrayData data[8];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadHstDt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadHstDt_t qt_meta_stringdata_ReadHstDt = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ReadHstDt"
QT_MOC_LITERAL(1, 10, 10), // "ReadHistDt"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "CJT188Obj"
QT_MOC_LITERAL(4, 32, 19), // "on_MonthBtn_clicked"
QT_MOC_LITERAL(5, 52, 18), // "on_DateBtn_clicked"
QT_MOC_LITERAL(6, 71, 18), // "on_TimeBtn_clicked"
QT_MOC_LITERAL(7, 90, 17) // "ReadHstDtResponse"

    },
    "ReadHstDt\0ReadHistDt\0\0CJT188Obj\0"
    "on_MonthBtn_clicked\0on_DateBtn_clicked\0"
    "on_TimeBtn_clicked\0ReadHstDtResponse"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadHstDt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void ReadHstDt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReadHstDt *_t = static_cast<ReadHstDt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReadHistDt((*reinterpret_cast< CJT188Obj(*)>(_a[1]))); break;
        case 1: _t->on_MonthBtn_clicked(); break;
        case 2: _t->on_DateBtn_clicked(); break;
        case 3: _t->on_TimeBtn_clicked(); break;
        case 4: _t->ReadHstDtResponse((*reinterpret_cast< CJT188Obj(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReadHstDt::*_t)(CJT188Obj );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReadHstDt::ReadHistDt)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ReadHstDt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ReadHstDt.data,
      qt_meta_data_ReadHstDt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReadHstDt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadHstDt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReadHstDt.stringdata0))
        return static_cast<void*>(const_cast< ReadHstDt*>(this));
    return QWidget::qt_metacast(_clname);
}

int ReadHstDt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ReadHstDt::ReadHistDt(CJT188Obj _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
