#ifndef IMPRIMIR_GRAFICOS_H
#define IMPRIMIR_GRAFICOS_H

#include <QDialog>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <modificar.h>
#include <string>
#include "grafo.h"

using namespace std;

namespace Ui {
    class Imprimir_graficos;
}

class Imprimir_graficos : public QDialog
{
    Q_OBJECT

public:
    explicit Imprimir_graficos(QWidget *parent = 0, string narchivo = "");
    ~Imprimir_graficos();

private:
    Ui::Imprimir_graficos *ui;
    string archivo;
    grafo *g;

    // Variables para el algoritmo de profundidad
    int pasgs, pcmps, plns;

    // Algoritmos
    void calcpert();
    void calccpm();
    // Recorridos
    void mostprof();
    void prof(grafo::vertice *vert, int nivel);
    void mostampl();

private slots:
    void on_rbProf_clicked();
    void on_rbAmpl_clicked();
    void on_rbCPM_clicked();
    void on_rbPERT_clicked();
    void on_buttonAbrir_clicked();

    void on_pushButton_clicked();
};

#endif // IMPRIMIR_GRAFICOS_H
