/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DistilleriaVeneta/view.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_view_t {
    QByteArrayData data[1];
    char stringdata0[5];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_view_t qt_meta_stringdata_view = {
    {
QT_MOC_LITERAL(0, 0, 4) // "view"

    },
    "view"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_view[] = {

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

void view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject view::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_view.data,
      qt_meta_data_view,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
<<<<<<< HEAD
struct qt_meta_stringdata_QReceiptitem_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QReceiptitem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QReceiptitem_t qt_meta_stringdata_QReceiptitem = {
    {
QT_MOC_LITERAL(0, 0, 12) // "QReceiptitem"

    },
    "QReceiptitem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QReceiptitem[] = {
=======
struct qt_meta_stringdata_QProduct_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QProduct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QProduct_t qt_meta_stringdata_QProduct = {
    {
QT_MOC_LITERAL(0, 0, 8) // "QProduct"

    },
    "QProduct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QProduct[] = {
>>>>>>> main

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

<<<<<<< HEAD
void QReceiptitem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
=======
void QProduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
>>>>>>> main
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

<<<<<<< HEAD
const QMetaObject QReceiptitem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QReceiptitem.data,
      qt_meta_data_QReceiptitem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QReceiptitem::metaObject() const
=======
const QMetaObject QProduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QProduct.data,
      qt_meta_data_QProduct,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QProduct::metaObject() const
>>>>>>> main
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

<<<<<<< HEAD
void *QReceiptitem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QReceiptitem.stringdata0))
=======
void *QProduct::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QProduct.stringdata0))
>>>>>>> main
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

<<<<<<< HEAD
int QReceiptitem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
=======
int QProduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
>>>>>>> main
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
<<<<<<< HEAD
struct qt_meta_stringdata_QProduct_t {
    QByteArrayData data[1];
    char stringdata0[9];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QProduct_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QProduct_t qt_meta_stringdata_QProduct = {
    {
QT_MOC_LITERAL(0, 0, 8) // "QProduct"

    },
    "QProduct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QProduct[] = {
=======
struct qt_meta_stringdata_QReceiptitem_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QReceiptitem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QReceiptitem_t qt_meta_stringdata_QReceiptitem = {
    {
QT_MOC_LITERAL(0, 0, 12) // "QReceiptitem"

    },
    "QReceiptitem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QReceiptitem[] = {
>>>>>>> main

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

<<<<<<< HEAD
void QProduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
=======
void QReceiptitem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
>>>>>>> main
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

<<<<<<< HEAD
const QMetaObject QProduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QProduct.data,
      qt_meta_data_QProduct,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QProduct::metaObject() const
=======
const QMetaObject QReceiptitem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QReceiptitem.data,
      qt_meta_data_QReceiptitem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QReceiptitem::metaObject() const
>>>>>>> main
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

<<<<<<< HEAD
void *QProduct::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QProduct.stringdata0))
=======
void *QReceiptitem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QReceiptitem.stringdata0))
>>>>>>> main
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

<<<<<<< HEAD
int QProduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
=======
int QReceiptitem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
>>>>>>> main
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
