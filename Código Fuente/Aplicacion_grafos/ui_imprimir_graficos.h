/********************************************************************************
** Form generated from reading UI file 'imprimir_graficos.ui'
**
** Created: Wed Apr 27 13:52:11 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPRIMIR_GRAFICOS_H
#define UI_IMPRIMIR_GRAFICOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Imprimir_graficos
{
public:
    QListWidget *listacts;
    QPushButton *pushButton;
    QPushButton *buttonAbrir;
    QGroupBox *groupBox;
    QRadioButton *rbPERT;
    QRadioButton *rbCPM;
    QLabel *label_9;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *alglns;
    QLineEdit *algcmp;
    QLineEdit *algasg;
    QLineEdit *algtmp;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QRadioButton *rbAmpl;
    QRadioButton *rbProf;
    QLabel *label_6;
    QLineEdit *reclns;
    QLabel *label_8;
    QLineEdit *reccmp;
    QLineEdit *rectmp;
    QLineEdit *recasg;
    QLabel *label_5;
    QLabel *label_10;

    void setupUi(QDialog *Imprimir_graficos)
    {
        if (Imprimir_graficos->objectName().isEmpty())
            Imprimir_graficos->setObjectName(QString::fromUtf8("Imprimir_graficos"));
        Imprimir_graficos->resize(649, 377);
        listacts = new QListWidget(Imprimir_graficos);
        listacts->setObjectName(QString::fromUtf8("listacts"));
        listacts->setGeometry(QRect(20, 20, 311, 341));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Semibold"));
        font.setBold(true);
        font.setWeight(75);
        listacts->setFont(font);
        pushButton = new QPushButton(Imprimir_graficos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 330, 111, 31));
        buttonAbrir = new QPushButton(Imprimir_graficos);
        buttonAbrir->setObjectName(QString::fromUtf8("buttonAbrir"));
        buttonAbrir->setGeometry(QRect(520, 330, 111, 31));
        groupBox = new QGroupBox(Imprimir_graficos);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(340, 20, 311, 141));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        rbPERT = new QRadioButton(groupBox);
        rbPERT->setObjectName(QString::fromUtf8("rbPERT"));
        rbPERT->setEnabled(true);
        rbPERT->setGeometry(QRect(10, 20, 241, 21));
        rbCPM = new QRadioButton(groupBox);
        rbCPM->setObjectName(QString::fromUtf8("rbCPM"));
        rbCPM->setEnabled(true);
        rbCPM->setGeometry(QRect(10, 50, 241, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(150, 110, 81, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 81, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 80, 81, 16));
        alglns = new QLineEdit(groupBox);
        alglns->setObjectName(QString::fromUtf8("alglns"));
        alglns->setGeometry(QRect(200, 80, 91, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        alglns->setFont(font1);
        alglns->setReadOnly(true);
        algcmp = new QLineEdit(groupBox);
        algcmp->setObjectName(QString::fromUtf8("algcmp"));
        algcmp->setGeometry(QRect(90, 110, 51, 20));
        algcmp->setFont(font1);
        algcmp->setReadOnly(true);
        algasg = new QLineEdit(groupBox);
        algasg->setObjectName(QString::fromUtf8("algasg"));
        algasg->setGeometry(QRect(90, 80, 51, 20));
        algasg->setFont(font1);
        algasg->setReadOnly(true);
        algtmp = new QLineEdit(groupBox);
        algtmp->setObjectName(QString::fromUtf8("algtmp"));
        algtmp->setGeometry(QRect(200, 110, 91, 20));
        algtmp->setFont(font1);
        algtmp->setReadOnly(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 81, 16));
        groupBox_2 = new QGroupBox(Imprimir_graficos);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(340, 170, 311, 141));
        rbAmpl = new QRadioButton(groupBox_2);
        rbAmpl->setObjectName(QString::fromUtf8("rbAmpl"));
        rbAmpl->setGeometry(QRect(10, 20, 231, 21));
        rbProf = new QRadioButton(groupBox_2);
        rbProf->setObjectName(QString::fromUtf8("rbProf"));
        rbProf->setGeometry(QRect(10, 50, 231, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 110, 81, 16));
        reclns = new QLineEdit(groupBox_2);
        reclns->setObjectName(QString::fromUtf8("reclns"));
        reclns->setGeometry(QRect(200, 80, 91, 20));
        reclns->setFont(font1);
        reclns->setReadOnly(true);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(150, 80, 81, 16));
        reccmp = new QLineEdit(groupBox_2);
        reccmp->setObjectName(QString::fromUtf8("reccmp"));
        reccmp->setGeometry(QRect(90, 110, 51, 20));
        reccmp->setFont(font1);
        reccmp->setReadOnly(true);
        rectmp = new QLineEdit(groupBox_2);
        rectmp->setObjectName(QString::fromUtf8("rectmp"));
        rectmp->setGeometry(QRect(200, 110, 91, 20));
        rectmp->setFont(font1);
        rectmp->setReadOnly(true);
        recasg = new QLineEdit(groupBox_2);
        recasg->setObjectName(QString::fromUtf8("recasg"));
        recasg->setGeometry(QRect(90, 80, 51, 20));
        recasg->setFont(font1);
        recasg->setReadOnly(true);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 80, 81, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 110, 81, 16));

        retranslateUi(Imprimir_graficos);

        QMetaObject::connectSlotsByName(Imprimir_graficos);
    } // setupUi

    void retranslateUi(QDialog *Imprimir_graficos)
    {
        Imprimir_graficos->setWindowTitle(QApplication::translate("Imprimir_graficos", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Imprimir_graficos", "Modificar actividad", 0, QApplication::UnicodeUTF8));
        buttonAbrir->setText(QApplication::translate("Imprimir_graficos", "Abrir nuevo grafo", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Imprimir_graficos", "Algoritmo", 0, QApplication::UnicodeUTF8));
        rbPERT->setText(QApplication::translate("Imprimir_graficos", "Program Evaluation and Review Technique", 0, QApplication::UnicodeUTF8));
        rbCPM->setText(QApplication::translate("Imprimir_graficos", "Critical Path Method", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Imprimir_graficos", "Tiempo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Imprimir_graficos", "Asignaciones", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Imprimir_graficos", "L\303\255neas", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Imprimir_graficos", "Comparaciones", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Imprimir_graficos", "Recorrido", 0, QApplication::UnicodeUTF8));
        rbAmpl->setText(QApplication::translate("Imprimir_graficos", "Amplitud", 0, QApplication::UnicodeUTF8));
        rbProf->setText(QApplication::translate("Imprimir_graficos", "Profundidad", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Imprimir_graficos", "Comparaciones", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Imprimir_graficos", "L\303\255neas", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Imprimir_graficos", "Asignaciones", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Imprimir_graficos", "Tiempo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Imprimir_graficos: public Ui_Imprimir_graficos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPRIMIR_GRAFICOS_H
