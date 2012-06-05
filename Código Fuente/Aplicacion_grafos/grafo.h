#ifndef GRAFO_H
#define GRAFO_H

#include "string"
#include "string.h"
#include <iostream>

using namespace std;

class grafo
{
public:
    grafo();

    struct vertice;

    // Estructura de un arco
    struct arco    {
        char nombre[20];
        int tiempo;
        vertice *destino;
        arco *sig;
        arco(char *nomb, int t) {
            strcpy(nombre, nomb);
            tiempo = t;
            destino = NULL;
            sig = NULL;
        }
    };
    // Elemento subarco, para sublistas
    struct subarco {

        arco *destino;
        subarco *sig;
        subarco(arco *dest) {
            destino = dest;
            sig = NULL;
        }
    };
    // Vertice
    struct vertice {
        int id;
        double et;
        subarco *pred, *sigarco;
        vertice *sig;
        vertice(int nid) {
            id = nid; et = 0;
            pred = NULL; sigarco = NULL;
            sig = NULL;
        }
    };

    int vertc;
    vertice *vertinicio;
    vertice *vertfin;
    arco *arcinicio;

    string rutac;

    int cmps, asgs, lns;

    void leer(string archivo);
    arco *buscar(char *nombre);

    bool modificartiempo(string nombre, int ntiempo);
    arco *buscar(string nombre);

    void cpm();
    void pert();

private:
    void agregararco(arco *nuevo);
    void agregarvert(vertice *nuevo);
    void cerrargrafo();
    void insertararco(char texto[]);
    void insertararco(arco *nuevo, subarco *predecesores);
    vertice *espredecesor(subarco *lista);
    int totalpreds(subarco *lista);
    void calcet(arco *origen, vertice *vert, double tiempo, bool directo);
    void rutacrit(string rc, vertice *vert, double tiempo);
    void limpiaret();
};

#endif // GRAFO_H
