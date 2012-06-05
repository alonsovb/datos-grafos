#include "modificar.h"
#include "ui_modificar.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

Modificar::Modificar(QWidget *parent, grafo *rg) :
    QDialog(parent),
    ui(new Ui::Modificar)
{
    ui->setupUi(this);

    g = rg;
    seleccionado = NULL;
    grafo::arco *temp = g->arcinicio;
    while (temp != NULL) {
        if (temp->tiempo != 0) {
            QString qs = "";
            qs.append(temp->nombre);
            ui->L_Act->addItem(qs);
        }
        temp = temp->sig;
    }
}

Modificar::~Modificar()
{
    delete ui;
}

void Modificar::on_L_Act_itemSelectionChanged()
{
    //actualizar_actividad();
    string nomb = ui->L_Act->currentItem()->text().toStdString();
    seleccionado = g->buscar(nomb);
    QString aux(seleccionado->nombre);
    ui->txtNombre->setText(aux);
    ui->txtSuc->setText(QString::number(seleccionado->destino->id));
    ui->tiempo->setText(QString::number(seleccionado->tiempo));
}


void Modificar::on_modificar_clicked()
{
    QString tiempo = QString (ui->tiempo->text());
    int itiempo =  atoi(tiempo.toStdString().c_str());
    seleccionado->tiempo = itiempo;
}

void Modificar::on_cerrar_clicked()
{
    this->hide();
}
