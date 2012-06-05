#ifndef MODIFICAR_H
#define MODIFICAR_H

#include <QDialog>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string"
#include "grafo.h"

namespace Ui {
    class Modificar;
}

class Modificar : public QDialog
{
    Q_OBJECT

public:
    explicit Modificar(QWidget *parent = 0, grafo *rg = 0);
    ~Modificar();

private:
    Ui::Modificar *ui;
    grafo *g;
    grafo::arco *seleccionado;

private slots:


    //void on_L_Act_clicked(QModelIndex index);
    void on_cerrar_clicked();
    void on_L_Act_itemSelectionChanged();
    void on_modificar_clicked();
};

#endif // MODIFICAR_H
