/****************************************************************************
** Meta object code from reading C++ file 'pictrueview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../pictrueview.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pictrueview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPictrueViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPictrueViewENDCLASS = QtMocHelpers::stringData(
    "PictrueView",
    "signalLanChanged",
    "",
    "onRadioButtonClicked",
    "QAbstractButton*",
    "button",
    "gray",
    "onSliderBinaryChanged",
    "threshold",
    "onBtnMeanFilter",
    "onslidergammaChanged",
    "value",
    "onBtnEdgeDetection"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPictrueViewENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[12];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[17];
    char stringdata5[7];
    char stringdata6[5];
    char stringdata7[22];
    char stringdata8[10];
    char stringdata9[16];
    char stringdata10[21];
    char stringdata11[6];
    char stringdata12[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPictrueViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPictrueViewENDCLASS_t qt_meta_stringdata_CLASSPictrueViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "PictrueView"
        QT_MOC_LITERAL(12, 16),  // "signalLanChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "onRadioButtonClicked"
        QT_MOC_LITERAL(51, 16),  // "QAbstractButton*"
        QT_MOC_LITERAL(68, 6),  // "button"
        QT_MOC_LITERAL(75, 4),  // "gray"
        QT_MOC_LITERAL(80, 21),  // "onSliderBinaryChanged"
        QT_MOC_LITERAL(102, 9),  // "threshold"
        QT_MOC_LITERAL(112, 15),  // "onBtnMeanFilter"
        QT_MOC_LITERAL(128, 20),  // "onslidergammaChanged"
        QT_MOC_LITERAL(149, 5),  // "value"
        QT_MOC_LITERAL(155, 18)   // "onBtnEdgeDetection"
    },
    "PictrueView",
    "signalLanChanged",
    "",
    "onRadioButtonClicked",
    "QAbstractButton*",
    "button",
    "gray",
    "onSliderBinaryChanged",
    "threshold",
    "onBtnMeanFilter",
    "onslidergammaChanged",
    "value",
    "onBtnEdgeDetection"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPictrueViewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   57,    2, 0x0a,    2 /* Public */,
       6,    0,   60,    2, 0x0a,    4 /* Public */,
       7,    1,   61,    2, 0x0a,    5 /* Public */,
       9,    0,   64,    2, 0x0a,    7 /* Public */,
      10,    1,   65,    2, 0x0a,    8 /* Public */,
      12,    0,   68,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PictrueView::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSPictrueViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPictrueViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPictrueViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PictrueView, std::true_type>,
        // method 'signalLanChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRadioButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractButton *, std::false_type>,
        // method 'gray'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSliderBinaryChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onBtnMeanFilter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onslidergammaChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onBtnEdgeDetection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PictrueView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PictrueView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLanChanged(); break;
        case 1: _t->onRadioButtonClicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 2: _t->gray(); break;
        case 3: _t->onSliderBinaryChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onBtnMeanFilter(); break;
        case 5: _t->onslidergammaChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onBtnEdgeDetection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PictrueView::*)();
            if (_t _q_method = &PictrueView::signalLanChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PictrueView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PictrueView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPictrueViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PictrueView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PictrueView::signalLanChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
