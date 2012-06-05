#include "aplicacion_grafos.h"
#include "ui_aplicacion_grafos.h"
#include <imprimir_graficos.h>


Aplicacion_grafos::Aplicacion_grafos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aplicacion_grafos)
{
    ui->setupUi(this);
    model = new QDirModel(this);
    model->setReadOnly(false);
    //model->setSorting(QDir::Dirs);
    ui->treeView->setModel(model);
}

Aplicacion_grafos::~Aplicacion_grafos()
{
    delete ui;
}

void Aplicacion_grafos::on_pushButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();

    //Dirección del grafo para cargar en memoria
   ui->label_2->setText(model->fileInfo(index).absoluteFilePath());

   string narchivo = model->fileInfo(index).absoluteFilePath().toStdString();
   if (model->fileInfo(index).isFile() && narchivo != "") {
   //Mostrar la ventana
       Imprimir_graficos *nventana = new Imprimir_graficos(this, narchivo);
       nventana->show();
       this->hide();
    }
}

void Aplicacion_grafos::on_treeView_clicked(QModelIndex index)
{
    // Mostrar el nombre de archivo seleccionado
    ui->label_2->setText(model->fileInfo(index).absoluteFilePath());
}
