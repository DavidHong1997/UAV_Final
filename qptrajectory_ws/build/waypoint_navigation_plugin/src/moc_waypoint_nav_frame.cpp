/****************************************************************************
** Meta object code from reading C++ file 'waypoint_nav_frame.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/waypoint_navigation_plugin/src/waypoint_nav_frame.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'waypoint_nav_frame.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame_t {
    QByteArrayData data[12];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame_t qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame = {
    {
QT_MOC_LITERAL(0, 0, 34), // "waypoint_nav_plugin::Waypoint..."
QT_MOC_LITERAL(1, 35, 20), // "publishButtonClicked"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 17), // "clearAllWaypoints"
QT_MOC_LITERAL(4, 75, 13), // "heightChanged"
QT_MOC_LITERAL(5, 89, 1), // "h"
QT_MOC_LITERAL(6, 91, 12), // "frameChanged"
QT_MOC_LITERAL(7, 104, 12), // "topicChanged"
QT_MOC_LITERAL(8, 117, 11), // "poseChanged"
QT_MOC_LITERAL(9, 129, 3), // "val"
QT_MOC_LITERAL(10, 133, 17), // "saveButtonClicked"
QT_MOC_LITERAL(11, 151, 17) // "loadButtonClicked"

    },
    "waypoint_nav_plugin::WaypointFrame\0"
    "publishButtonClicked\0\0clearAllWaypoints\0"
    "heightChanged\0h\0frameChanged\0topicChanged\0"
    "poseChanged\0val\0saveButtonClicked\0"
    "loadButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_waypoint_nav_plugin__WaypointFrame[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void waypoint_nav_plugin::WaypointFrame::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WaypointFrame *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->publishButtonClicked(); break;
        case 1: _t->clearAllWaypoints(); break;
        case 2: _t->heightChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->frameChanged(); break;
        case 4: _t->topicChanged(); break;
        case 5: _t->poseChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->saveButtonClicked(); break;
        case 7: _t->loadButtonClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject waypoint_nav_plugin::WaypointFrame::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame.data,
    qt_meta_data_waypoint_nav_plugin__WaypointFrame,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *waypoint_nav_plugin::WaypointFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *waypoint_nav_plugin::WaypointFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_waypoint_nav_plugin__WaypointFrame.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int waypoint_nav_plugin::WaypointFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
