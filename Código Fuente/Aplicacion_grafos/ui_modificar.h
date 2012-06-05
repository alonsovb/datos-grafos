/********************************************************************************
** Form generated from reading UI file 'modificar.ui'
**
** Created: Wed Apr 27 13:52:11 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICAR_H
#define UI_MODIFICAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Modificar
{
public:
    QPushButton *modificar;
    QLabel *label;
    QListWidget *L_Act;
    QLineEdit *txtNombre;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *tiempo;
    QPushButton *cerrar;
    QLabel *label_5;
    QLineEdit *txtSuc;

    void setupUi(QDialog *Modificar)
    {
        if (Modificar->objectName().isEmpty())
            Modificar->setObjectName(QString::fromUtf8("Modificar"));
        Modificar->resize(401, 343);
        modificar = new QPushButton(Modificar);
        modificar->setObjectName(QString::fromUtf8("modificar"));
        modificar->setGeometry(QRect(280, 290, 91, 31));
        label = new QLabel(Modificar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 16));
        L_Act = new QListWidget(Modificar);
        L_Act->setObjectName(QString::fromUtf8("L_Act"));
        L_Act->setGeometry(QRect(10, 40, 151, 281));
        txtNombre = new QLineEdit(Modificar);
        txtNombre->setObjectName(QString::fromUtf8("txtNombre"));
        txtNombre->setEnabled(true);
        txtNombre->setGeometry(QRect(270, 50, 113, 20));
        txtNombre->setReadOnly(true);
        label_2 = new QLabel(Modificar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 50, 81, 16));
        label_3 = new QLabel(Modificar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 160, 81, 16));
        tiempo = new QLineEdit(Modificar);
        tiempo->setObjectName(QString::fromUtf8("tiempo"));
        tiempo->setGeometry(QRect(270, 160, 113, 20));
        cerrar = new QPushButton(Modificar);
        cerrar->setObjectName(QString::fromUtf8("cerrar"));
        cerrar->setGeometry(QRect(180, 290, 91, 31));
        label_5 = new QLabel(Modificar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 80, 91, 16));
        txtSuc = new QLineEdit(Modificar);
        txtSuc->setObjectName(QString::fromUtf8("txtSuc"));
        txtSuc->setEnabled(true);
        txtSuc->setGeometry(QRect(270, 80, 113, 20));
        txtSuc->setReadOnly(true);

        retranslateUi(Modificar);

        QMetaObject::connectSlotsByName(Modificar);
    } // setupUi

    void retranslateUi(QDialog *Modificar)
    {
        Modificar->setWindowTitle(QApplication::translate("Modificar", "Dialog", 0, QApplication::UnicodeUTF8));
        modificar->setText(QApplication::translate("Modificar", "Modificar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Modificar", "Actvidades", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Modificar", "Nombre", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Modificar", "Nuevo tiempo", 0, QApplication::UnicodeUTF8));
        cerrar->setText(QApplication::translate("Modificar", "Cerrar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Modificar", "Vertice sucesor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Modificar: public Ui_Modificar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICAR_H
