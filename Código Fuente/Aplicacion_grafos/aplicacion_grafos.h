#ifndef APLICACION_GRAFOS_H
#define APLICACION_GRAFOS_H

#include <QtCore>
#include <QtGui>
#include <imprimir_graficos.h>

namespace Ui {
    class Aplicacion_grafos;
}

class Aplicacion_grafos : public QMainWindow
{
    Q_OBJECT

public:
    explicit Aplicacion_grafos(QWidget *parent = 0);
    ~Aplicacion_grafos();

private:
    Ui::Aplicacion_grafos *ui;
    QDirModel *model;

private slots:
    void on_treeView_clicked(QModelIndex index);
    void on_pushButton_clicked();
};

#endif // APLICACION_GRAFOS_H
