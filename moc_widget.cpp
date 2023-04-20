/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[60];
    char stringdata0[1156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 8), // "get_data"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "uint8_t*"
QT_MOC_LITERAL(4, 26, 4), // "buff"
QT_MOC_LITERAL(5, 31, 12), // "get_rgb_data"
QT_MOC_LITERAL(6, 44, 20), // "On_btn_start_clicked"
QT_MOC_LITERAL(7, 65, 19), // "On_btn_stop_clicked"
QT_MOC_LITERAL(8, 85, 20), // "On_btn_black_clicked"
QT_MOC_LITERAL(9, 106, 20), // "On_btn_white_clicked"
QT_MOC_LITERAL(10, 127, 22), // "On_btn_capture_clicked"
QT_MOC_LITERAL(11, 150, 8), // "get_mask"
QT_MOC_LITERAL(12, 159, 5), // "char*"
QT_MOC_LITERAL(13, 165, 7), // "get_buf"
QT_MOC_LITERAL(14, 173, 12), // "get_mask_rgb"
QT_MOC_LITERAL(15, 186, 14), // "get_valve_data"
QT_MOC_LITERAL(16, 201, 10), // "valve_data"
QT_MOC_LITERAL(17, 212, 22), // "get_send_to_up_machine"
QT_MOC_LITERAL(18, 235, 6), // "float*"
QT_MOC_LITERAL(19, 242, 7), // "sendbuf"
QT_MOC_LITERAL(20, 250, 19), // "readfrom_up_machine"
QT_MOC_LITERAL(21, 270, 22), // "readfrom_lower_machine"
QT_MOC_LITERAL(22, 293, 25), // "On_btn_sendsingle_clicked"
QT_MOC_LITERAL(23, 319, 23), // "On_btn_autosend_clicked"
QT_MOC_LITERAL(24, 343, 16), // "on_btn_1_clicked"
QT_MOC_LITERAL(25, 360, 16), // "on_btn_2_clicked"
QT_MOC_LITERAL(26, 377, 16), // "on_btn_3_clicked"
QT_MOC_LITERAL(27, 394, 16), // "on_btn_4_clicked"
QT_MOC_LITERAL(28, 411, 16), // "on_btn_5_clicked"
QT_MOC_LITERAL(29, 428, 16), // "on_btn_6_clicked"
QT_MOC_LITERAL(30, 445, 16), // "on_btn_7_clicked"
QT_MOC_LITERAL(31, 462, 16), // "on_btn_8_clicked"
QT_MOC_LITERAL(32, 479, 16), // "on_btn_9_clicked"
QT_MOC_LITERAL(33, 496, 16), // "on_btn_0_clicked"
QT_MOC_LITERAL(34, 513, 20), // "on_btn_clear_clicked"
QT_MOC_LITERAL(35, 534, 18), // "on_btn_del_clicked"
QT_MOC_LITERAL(36, 553, 21), // "on_btn_ensure_clicked"
QT_MOC_LITERAL(37, 575, 19), // "on_btn_back_clicked"
QT_MOC_LITERAL(38, 595, 24), // "on_btn_send_plus_clicked"
QT_MOC_LITERAL(39, 620, 23), // "on_btn_send_min_clicked"
QT_MOC_LITERAL(40, 644, 24), // "On_btn_threshold_clicked"
QT_MOC_LITERAL(41, 669, 24), // "on_btn_set_lower_clicked"
QT_MOC_LITERAL(42, 694, 25), // "on_btn_set_camera_clicked"
QT_MOC_LITERAL(43, 720, 18), // "on_btn_set_clicked"
QT_MOC_LITERAL(44, 739, 24), // "on_btn_rgb_white_clicked"
QT_MOC_LITERAL(45, 764, 24), // "on_btn_rgb_black_clicked"
QT_MOC_LITERAL(46, 789, 26), // "on_btn_save_enable_clicked"
QT_MOC_LITERAL(47, 816, 29), // "on_btn_save_disenable_clicked"
QT_MOC_LITERAL(48, 846, 28), // "on_btn_open_conveyor_clicked"
QT_MOC_LITERAL(49, 875, 29), // "on_btn_close_conveyor_clicked"
QT_MOC_LITERAL(50, 905, 24), // "on_btn_open_lamp_clicked"
QT_MOC_LITERAL(51, 930, 25), // "on_btn_close_lamp_clicked"
QT_MOC_LITERAL(52, 956, 21), // "on_btn_exit_2_clicked"
QT_MOC_LITERAL(53, 978, 21), // "on_btn_0to3_2_clicked"
QT_MOC_LITERAL(54, 1000, 31), // "on_btn_send_single_long_clicked"
QT_MOC_LITERAL(55, 1032, 29), // "on_btn_autosend_valve_clicked"
QT_MOC_LITERAL(56, 1062, 30), // "on_radioButton_manul_2_clicked"
QT_MOC_LITERAL(57, 1093, 7), // "checked"
QT_MOC_LITERAL(58, 1101, 28), // "on_radioButton_manul_clicked"
QT_MOC_LITERAL(59, 1130, 25) // "on_btn_lamp_reset_clicked"

    },
    "Widget\0get_data\0\0uint8_t*\0buff\0"
    "get_rgb_data\0On_btn_start_clicked\0"
    "On_btn_stop_clicked\0On_btn_black_clicked\0"
    "On_btn_white_clicked\0On_btn_capture_clicked\0"
    "get_mask\0char*\0get_buf\0get_mask_rgb\0"
    "get_valve_data\0valve_data\0"
    "get_send_to_up_machine\0float*\0sendbuf\0"
    "readfrom_up_machine\0readfrom_lower_machine\0"
    "On_btn_sendsingle_clicked\0"
    "On_btn_autosend_clicked\0on_btn_1_clicked\0"
    "on_btn_2_clicked\0on_btn_3_clicked\0"
    "on_btn_4_clicked\0on_btn_5_clicked\0"
    "on_btn_6_clicked\0on_btn_7_clicked\0"
    "on_btn_8_clicked\0on_btn_9_clicked\0"
    "on_btn_0_clicked\0on_btn_clear_clicked\0"
    "on_btn_del_clicked\0on_btn_ensure_clicked\0"
    "on_btn_back_clicked\0on_btn_send_plus_clicked\0"
    "on_btn_send_min_clicked\0"
    "On_btn_threshold_clicked\0"
    "on_btn_set_lower_clicked\0"
    "on_btn_set_camera_clicked\0on_btn_set_clicked\0"
    "on_btn_rgb_white_clicked\0"
    "on_btn_rgb_black_clicked\0"
    "on_btn_save_enable_clicked\0"
    "on_btn_save_disenable_clicked\0"
    "on_btn_open_conveyor_clicked\0"
    "on_btn_close_conveyor_clicked\0"
    "on_btn_open_lamp_clicked\0"
    "on_btn_close_lamp_clicked\0"
    "on_btn_exit_2_clicked\0on_btn_0to3_2_clicked\0"
    "on_btn_send_single_long_clicked\0"
    "on_btn_autosend_valve_clicked\0"
    "on_radioButton_manul_2_clicked\0checked\0"
    "on_radioButton_manul_clicked\0"
    "on_btn_lamp_reset_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  264,    2, 0x08 /* Private */,
       5,    1,  267,    2, 0x08 /* Private */,
       6,    0,  270,    2, 0x08 /* Private */,
       7,    0,  271,    2, 0x08 /* Private */,
       8,    0,  272,    2, 0x08 /* Private */,
       9,    0,  273,    2, 0x08 /* Private */,
      10,    0,  274,    2, 0x08 /* Private */,
      11,    1,  275,    2, 0x08 /* Private */,
      14,    1,  278,    2, 0x08 /* Private */,
      15,    1,  281,    2, 0x08 /* Private */,
      17,    1,  284,    2, 0x08 /* Private */,
      20,    0,  287,    2, 0x08 /* Private */,
      21,    0,  288,    2, 0x08 /* Private */,
      22,    0,  289,    2, 0x08 /* Private */,
      23,    0,  290,    2, 0x08 /* Private */,
      24,    0,  291,    2, 0x08 /* Private */,
      25,    0,  292,    2, 0x08 /* Private */,
      26,    0,  293,    2, 0x08 /* Private */,
      27,    0,  294,    2, 0x08 /* Private */,
      28,    0,  295,    2, 0x08 /* Private */,
      29,    0,  296,    2, 0x08 /* Private */,
      30,    0,  297,    2, 0x08 /* Private */,
      31,    0,  298,    2, 0x08 /* Private */,
      32,    0,  299,    2, 0x08 /* Private */,
      33,    0,  300,    2, 0x08 /* Private */,
      34,    0,  301,    2, 0x08 /* Private */,
      35,    0,  302,    2, 0x08 /* Private */,
      36,    0,  303,    2, 0x08 /* Private */,
      37,    0,  304,    2, 0x08 /* Private */,
      38,    0,  305,    2, 0x08 /* Private */,
      39,    0,  306,    2, 0x08 /* Private */,
      40,    0,  307,    2, 0x08 /* Private */,
      41,    0,  308,    2, 0x08 /* Private */,
      42,    0,  309,    2, 0x08 /* Private */,
      43,    0,  310,    2, 0x08 /* Private */,
      44,    0,  311,    2, 0x08 /* Private */,
      45,    0,  312,    2, 0x08 /* Private */,
      46,    0,  313,    2, 0x08 /* Private */,
      47,    0,  314,    2, 0x08 /* Private */,
      48,    0,  315,    2, 0x08 /* Private */,
      49,    0,  316,    2, 0x08 /* Private */,
      50,    0,  317,    2, 0x08 /* Private */,
      51,    0,  318,    2, 0x08 /* Private */,
      52,    0,  319,    2, 0x08 /* Private */,
      53,    0,  320,    2, 0x08 /* Private */,
      54,    0,  321,    2, 0x08 /* Private */,
      55,    0,  322,    2, 0x08 /* Private */,
      56,    1,  323,    2, 0x08 /* Private */,
      58,    1,  326,    2, 0x08 /* Private */,
      59,    0,  329,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 3,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get_data((*reinterpret_cast< uint8_t*(*)>(_a[1]))); break;
        case 1: _t->get_rgb_data((*reinterpret_cast< uint8_t*(*)>(_a[1]))); break;
        case 2: _t->On_btn_start_clicked(); break;
        case 3: _t->On_btn_stop_clicked(); break;
        case 4: _t->On_btn_black_clicked(); break;
        case 5: _t->On_btn_white_clicked(); break;
        case 6: _t->On_btn_capture_clicked(); break;
        case 7: _t->get_mask((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 8: _t->get_mask_rgb((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 9: _t->get_valve_data((*reinterpret_cast< uint8_t*(*)>(_a[1]))); break;
        case 10: _t->get_send_to_up_machine((*reinterpret_cast< float*(*)>(_a[1]))); break;
        case 11: _t->readfrom_up_machine(); break;
        case 12: _t->readfrom_lower_machine(); break;
        case 13: _t->On_btn_sendsingle_clicked(); break;
        case 14: _t->On_btn_autosend_clicked(); break;
        case 15: _t->on_btn_1_clicked(); break;
        case 16: _t->on_btn_2_clicked(); break;
        case 17: _t->on_btn_3_clicked(); break;
        case 18: _t->on_btn_4_clicked(); break;
        case 19: _t->on_btn_5_clicked(); break;
        case 20: _t->on_btn_6_clicked(); break;
        case 21: _t->on_btn_7_clicked(); break;
        case 22: _t->on_btn_8_clicked(); break;
        case 23: _t->on_btn_9_clicked(); break;
        case 24: _t->on_btn_0_clicked(); break;
        case 25: _t->on_btn_clear_clicked(); break;
        case 26: _t->on_btn_del_clicked(); break;
        case 27: _t->on_btn_ensure_clicked(); break;
        case 28: _t->on_btn_back_clicked(); break;
        case 29: _t->on_btn_send_plus_clicked(); break;
        case 30: _t->on_btn_send_min_clicked(); break;
        case 31: _t->On_btn_threshold_clicked(); break;
        case 32: _t->on_btn_set_lower_clicked(); break;
        case 33: _t->on_btn_set_camera_clicked(); break;
        case 34: _t->on_btn_set_clicked(); break;
        case 35: _t->on_btn_rgb_white_clicked(); break;
        case 36: _t->on_btn_rgb_black_clicked(); break;
        case 37: _t->on_btn_save_enable_clicked(); break;
        case 38: _t->on_btn_save_disenable_clicked(); break;
        case 39: _t->on_btn_open_conveyor_clicked(); break;
        case 40: _t->on_btn_close_conveyor_clicked(); break;
        case 41: _t->on_btn_open_lamp_clicked(); break;
        case 42: _t->on_btn_close_lamp_clicked(); break;
        case 43: _t->on_btn_exit_2_clicked(); break;
        case 44: _t->on_btn_0to3_2_clicked(); break;
        case 45: _t->on_btn_send_single_long_clicked(); break;
        case 46: _t->on_btn_autosend_valve_clicked(); break;
        case 47: _t->on_radioButton_manul_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_radioButton_manul_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_btn_lamp_reset_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 50;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
