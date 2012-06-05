#include "imprimir_graficos.h"
#include "ui_imprimir_graficos.h"
#include "modificar.h"
#include "aplicacion_grafos.h"
#include "string"
#include "grafo.h"

Imprimir_graficos::Imprimir_graficos(QWidget *parent, string narchivo) :
    QDialog(parent),
    ui(new Ui::Imprimir_graficos)
{
    ui->setupUi(this);
    archivo = narchivo;
    g = new grafo();
    g->leer(archivo);
    calccpm();
    mostampl();
}

Imprimir_graficos::~Imprimir_graficos()
{
    delete ui;
}


void Imprimir_graficos::on_pushButton_clicked()
{
    //Mostrar la ventana
    Modificar *nmod = new Modificar(this, g);
    nmod->show();
}

void Imprimir_graficos::calcpert() {

    QTime tiempo(0, 0, 0, 0);
    int t = 0;
    tiempo.start();
    // Llamar al algoritmo pert
    g->pert();
    t = tiempo.elapsed();
    ui->algasg->setText(QString::number(g->asgs));
    ui->algcmp->setText(QString::number(g->asgs));
    ui->alglns->setText(QString::number(g->lns));
    ui->algtmp->setText(QString::number(t) + " ms.");

}

void Imprimir_graficos::calccpm() {
    QTime tiempo(0, 0, 0, 0);
    int t = 0;
    tiempo.start();
    // Llamar al algoritmo cpm
    g->cpm();
    t = tiempo.elapsed();
    ui->algasg->setText(QString::number(g->asgs));
    ui->algcmp->setText(QString::number(g->asgs));
    ui->alglns->setText(QString::number(g->lns));
    ui->algtmp->setText(QString::number(t) + " ms.");
}

void Imprimir_graficos::mostampl() {

    int asgs = 0, cmps = 0, lns = 0, t = 0;
    ui->listacts->clear();
    QTime tiempo(0, 0, 0, 0);

    tiempo.start();

    // Recorrido por amplitud
    asgs += 2;
    grafo::vertice *temp = g->vertinicio;
    cmps++;
    while (temp != NULL) {
        cmps++; asgs++;
        QString vertitem =
                "Vertice : " + QString::number(temp->id) + " ( ";

        // Mostrar los predecesores y su informacion
        cmps++;
        if (temp->pred == NULL) {
            asgs++;
            vertitem += " -- ";
        }
        else {
            asgs++;
            grafo::subarco *sublista = temp->pred;
            cmps++;
            while (sublista != NULL) {
                cmps++; lns++;
                vertitem.append(sublista->destino->nombre);
                vertitem += " ";
                sublista = sublista->sig;
                asgs += 2;
            }
        }
        asgs++;
        vertitem += ") - ET: " + QString::number(temp->et);

        ui->listacts->addItem(vertitem);

        // Imprimir los sucesores y su informacion
        asgs++;
        grafo::subarco *sucs = temp->sigarco;
        cmps++;
        while (sucs != NULL) {
            cmps++; asgs++;
            QString sucitem = " - Arco: ";
            sucitem.append(sucs->destino->nombre);
            sucitem += " \t t: " + QString::number(sucs->destino->tiempo);
            sucitem += " \t dest: " + QString::number(sucs->destino->destino->id);
            ui->listacts->addItem(sucitem);
            sucs = sucs->sig;
            lns += 2; asgs += 4;
        }
        asgs++;
        temp = temp->sig;
    }
    lns += cmps + asgs;
    ui->listacts->addItem(QString::fromStdString(g->rutac));
    t = tiempo.elapsed();
    ui->recasg->setText(QString::number(asgs));
    ui->reccmp->setText(QString::number(cmps));
    ui->reclns->setText(QString::number(lns));
    ui->rectmp->setText(QString::number(t) + " ms.");
}

void Imprimir_graficos::mostprof() {

    pasgs = 0; pcmps = 0; plns = 0;
    QTime tiempo(0, 0, 0, 0);
    int t = 0;
    ui->listacts->clear();

    tiempo.start();
    // Llamada al metodo recursivo de profundidad
    prof(g->vertinicio, 0);
    t = tiempo.elapsed();
    plns += pasgs + pcmps;

    ui->listacts->addItem(QString::fromStdString(g->rutac));
    ui->recasg->setText(QString::number(pasgs));
    ui->reccmp->setText(QString::number(pcmps));
    ui->reclns->setText(QString::number(plns));
    ui->rectmp->setText(QString::number(t) + " ms.");
}

void Imprimir_graficos::prof(grafo::vertice *vert, int nivel) {
    pcmps++;
    if (vert != NULL) {
        pasgs++;
        grafo::subarco *temp = vert->sigarco;
        pcmps++;
        // Imprimir cada arco
        while (temp != NULL) {
            pcmps++;
            pasgs++;
            QString itemtxt = "";
            pcmps++; pasgs++;
            for (int i = 0; i < nivel; i++) {
                pcmps++; pasgs += 2;
                itemtxt += "  |   ";
            }
            itemtxt += "(" + QString::number(vert->id) + ") Arco: ";
            itemtxt.append(temp->destino->nombre);
            itemtxt += " - t: " + QString::number(temp->destino->tiempo)
                       + " - dest (" + QString::number(temp->destino->destino->id) + ")";
            ui->listacts->addItem(itemtxt);

            // Realizar la llamada recursiva con un nivel superior
            prof(temp->destino->destino, nivel + 1);
            temp = temp->sig;
            pasgs += 4;
            plns++;
        }
    }
}

void Imprimir_graficos::on_buttonAbrir_clicked()
{
    // Llamar a la venta inicial
    Aplicacion_grafos *ag = new Aplicacion_grafos();
    ag->show();
    this->hide();
}

void Imprimir_graficos::on_rbPERT_clicked()
{
    // Cambiar el algoritmo a pert
    calcpert();
    if (ui->rbProf->isChecked())
        mostprof();
    else
        mostampl();
}

void Imprimir_graficos::on_rbCPM_clicked()
{
    // Llamar al algoritmo cpm
    calccpm();
    if (ui->rbProf->isChecked())
        mostprof();
    else
        mostampl();
}

void Imprimir_graficos::on_rbAmpl_clicked()
{
    // Mostrar con el recorrido por amplitud
    mostampl();
}

void Imprimir_graficos::on_rbProf_clicked()
{
    // Mostrar con el recorrido por profundidad
    mostprof();
}
