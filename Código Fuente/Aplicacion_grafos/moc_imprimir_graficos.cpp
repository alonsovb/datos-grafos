/****************************************************************************
** Meta object code from reading C++ file 'imprimir_graficos.h'
**
** Created: Wed Apr 27 13:13:10 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imprimir_graficos.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imprimir_graficos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Imprimir_graficos[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      39,   18,   18,   18, 0x08,
      59,   18,   18,   18, 0x08,
      78,   18,   18,   18, 0x08,
      98,   18,   18,   18, 0x08,
     123,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Imprimir_graficos[] = {
    "Imprimir_graficos\0\0on_rbProf_clicked()\0"
    "on_rbAmpl_clicked()\0on_rbCPM_clicked()\0"
    "on_rbPERT_clicked()\0on_buttonAbrir_clicked()\0"
    "on_pushButton_clicked()\0"
};

const QMetaObject Imprimir_graficos::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Imprimir_graficos,
      qt_meta_data_Imprimir_graficos, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Imprimir_graficos::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Imprimir_graficos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Imprimir_graficos::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Imprimir_graficos))
        return static_cast<void*>(const_cast< Imprimir_graficos*>(this));
    return QDialog::qt_metacast(_clname);
}

int Imprimir_graficos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_rbProf_clicked(); break;
        case 1: on_rbAmpl_clicked(); break;
        case 2: on_rbCPM_clicked(); break;
        case 3: on_rbPERT_clicked(); break;
        case 4: on_buttonAbrir_clicked(); break;
        case 5: on_pushButton_clicked(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
