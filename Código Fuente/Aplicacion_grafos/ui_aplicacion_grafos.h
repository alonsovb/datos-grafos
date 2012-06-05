/********************************************************************************
** Form generated from reading UI file 'aplicacion_grafos.ui'
**
** Created: Wed Apr 27 13:55:23 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APLICACION_GRAFOS_H
#define UI_APLICACION_GRAFOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Aplicacion_grafos
{
public:
    QWidget *centralWidget;
    QTreeView *treeView;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Aplicacion_grafos)
    {
        if (Aplicacion_grafos->objectName().isEmpty())
            Aplicacion_grafos->setObjectName(QString::fromUtf8("Aplicacion_grafos"));
        Aplicacion_grafos->resize(400, 406);
        centralWidget = new QWidget(Aplicacion_grafos);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 30, 371, 271));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 321, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 310, 91, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 310, 271, 31));
        Aplicacion_grafos->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Aplicacion_grafos);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        Aplicacion_grafos->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Aplicacion_grafos);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Aplicacion_grafos->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Aplicacion_grafos);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Aplicacion_grafos->setStatusBar(statusBar);

        retranslateUi(Aplicacion_grafos);

        QMetaObject::connectSlotsByName(Aplicacion_grafos);
    } // setupUi

    void retranslateUi(QMainWindow *Aplicacion_grafos)
    {
        Aplicacion_grafos->setWindowTitle(QApplication::translate("Aplicacion_grafos", "Aplicacion_grafos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Aplicacion_grafos", "Seleccione la direccion del archivo del grafo:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Aplicacion_grafos", "Abrir Grafo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Aplicacion_grafos", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Aplicacion_grafos: public Ui_Aplicacion_grafos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APLICACION_GRAFOS_H
