#include "grafo.h"
#include "string"
#include "fstream"
#include "iostream"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

grafo::grafo()
{
    vertc = 0;
    cmps  = 0;
    asgs  = 0;
    lns   = 0;
    vertinicio = new vertice(vertc++);
    vertfin    = NULL;
    arcinicio  = NULL;
    rutac = "";
}

// Lee el contenido de un archivo que representa
// la estructura de un grafo y lo carga a memoria.
void grafo::leer(string nombre_archivo) {

    // Abrir el archivo recibido como string
    const char *char_nombre_archivo = nombre_archivo.c_str();
    fstream archivo;
    archivo.open(char_nombre_archivo, ios_base::in);

    cout << "Nombre del archivo: " << char_nombre_archivo << endl;
    if (archivo.is_open()) {
        int tamano = 0;
        archivo.seekg(0, ios_base::end);
        // Leer el tamano del archivo en bytes
        tamano = archivo.tellg();
        cout << "Tamano en bytes del archivo: " << tamano << endl;
        char texto[tamano];
        archivo.seekg(0);
        // Leer todo el contenido del archivo
        archivo.read(texto, tamano);

        int ultimoarco = 0;
        for (int i = 0; i < tamano; i++) {
            // Buscar caracteres separadores de arcos
            if (texto[i] == ';') {
                char arcot[i - ultimoarco];
                // Copiar el trozo de texto
                for (int j = 0; j < i - ultimoarco + 1; j++) {
                    arcot[j] = texto[j + ultimoarco];
                }
                arcot[i - ultimoarco + 1] = '\0';
                // Insertar el arco como texto
                insertararco(arcot);
                ultimoarco = i + 1;
            }
        }
        // Cerrar el grafo con un ultimo vertice
        cerrargrafo();
    }
}

// Buscar el puntero de un arco segun el nombre
grafo::arco *grafo::buscar(char *nombre) {
    arco *temp = arcinicio;
    // Recorrer la lista de arcos
    while (temp != NULL && strcmp(temp->nombre, nombre) != 0) {
        temp= temp->sig;
    }
    return temp;
}

// Buscar arco mediante el nombre en string
grafo::arco *grafo::buscar(string nombre) {
    // Convertir el texto a char[]
    char texto[20];
    int tamano = nombre.copy(texto, 20, 0);
    texto[tamano] = '\0';
    return buscar(texto);
}

// Agregar un puntero de arco a la lista general
void grafo::agregararco(arco *nuevo) {
    if (arcinicio == NULL)
        arcinicio = nuevo;
    else {
        arco *temp = arcinicio;
        while (temp->sig != NULL)
            temp = temp->sig;
        temp->sig = nuevo;
    }
}

// Agregar un puntero de vertice a la lista general
void grafo::agregarvert(vertice *nuevo) {
    vertice *temp = vertinicio;
    while (temp->sig != NULL)
        temp = temp->sig;
    temp->sig = nuevo;
}

// Crea un vertice final. Buscar arcos sin destino para el.
void grafo::cerrargrafo() {

    // Vertice final y sus predecesores
    subarco *preds = NULL;
    vertice *fin = new vertice(vertc);

    // Buscar arcos sin destinos
    arco *temp = arcinicio;
    while (temp != NULL) {
        if (temp->destino == NULL) {

            // Nuevo destino es ahora el fin
            temp->destino = fin;

            // Sublista de predecesores del fin
            subarco *nsarco = new subarco(temp);
            if (preds == NULL)
                preds = nsarco;
            else {
                subarco *subtemp = preds;
                while (subtemp->sig != NULL)
                    subtemp = subtemp->sig;
                subtemp->sig = nsarco;
            }
        }
        temp = temp->sig;
    }

    // Agregar los predecesores al fin
    fin->pred = preds;
    // Agregar vertice nuevo a la lista
    agregarvert(fin);
}

// Inserta un arco leyendo de un texto su informacion
void grafo::insertararco(char texto[]) {

    int i = 0, secciones = 0, ultima = 0, tiempo;
    char *nombre, *ctiempo, *preds;
    subarco *listaarcos = NULL;

    // Recorrer todo el segmento de texto
    while (texto[i] != '\0') {

        // Marcar cada separador como punto critico
        if (texto[i] == ',' || texto[i] == ';') {

            // Seccion 0 es el nombre del arco
            if (secciones == 0) {

                // Espacio para el nombre
                nombre = new char[i - ultima];
                // Copiar el dato del segmento de texto
                for (int j = 0; j < i - ultima; j++) {
                    nombre[j] = texto[j + ultima];
                }
                nombre[i - ultima] = '\0';

            } else if (secciones == 1) {

                // Espacio para el tiempo
                ctiempo = new char[i - ultima];
                for (int j = 0; j < i - ultima; j++) {
                    ctiempo[j] = texto[j + ultima];
                }
                ctiempo[i - ultima] = '\0';
                tiempo = atoi(ctiempo);

            } else {

                // Leer los predecesores y agregarlos a la sublista
                preds = new char[i - ultima];
                for (int j = 0; j < i - ultima; j++) {
                    preds[j] = texto[j + ultima];
                }
                preds[i - ultima] = '\0';

                // Si el predecesor es valido
                if (strcmp(preds, "0") != 0) {
                    subarco *nsarco = new subarco(buscar(preds));
                    if (nsarco->destino != NULL) {
                        // Buscar arco y agregarlo a la sublista
                        if (listaarcos == NULL)
                            listaarcos = nsarco;
                        else {
                            subarco *temp = listaarcos;
                            while (temp->sig != NULL)
                                temp = temp->sig;
                            temp->sig = nsarco;
                        }
                    } else
                        delete nsarco;
                }
            }
            ultima = i + 1;
            secciones++;
        }
        i++;
    }
    arco *narco = new arco(nombre, tiempo);
    insertararco(narco, listaarcos);
}

// Inserta un puntero de arco en la ubicacion indicada
// considerando sus predecesores
void grafo::insertararco(arco *nuevo, subarco *predecesores) {
    // En el caso de que no hayan predecesores
    if (predecesores == NULL) {
        // Insertar arco en el vertice inicial
        subarco *nuevosa = new subarco(nuevo);
        if (vertinicio->sigarco == NULL)
            vertinicio->sigarco = nuevosa;
        else {
            subarco *temp = vertinicio->sigarco;
            while (temp->sig != NULL)
                temp = temp->sig;
            temp->sig = nuevosa;
        }
        agregararco(nuevo);
    } else {
        // Buscar si existe un vertice que posea los predecesores necesarios
        vertice *vpred = espredecesor(predecesores);
        if (vpred == NULL) {
            // Nuevo vertice cuando no hay uno que lo anteceda
            vertice *nvert = new vertice(vertc++);
            agregarvert(nvert);
            nvert->pred = predecesores;

            // Buscar cada predecesor
            subarco *temp = predecesores;
            while (temp != NULL) {
                subarco *unpred = new subarco(temp->destino);
                vertice *unpredvert = espredecesor(unpred);
                // Si no es predecesor, se crea un ficticio
                if (unpredvert == NULL) {
                    vertice *nauxvert = new vertice(vertc++);
                    agregarvert(nauxvert);
                    nauxvert->pred = unpred;
                    // Crear ficticio nuevo
                    temp->destino->destino = nauxvert;
                    arco *ficticio = new arco("Fict.", 0);
                    ficticio->destino = nvert;
                    agregararco(ficticio);
                    nauxvert->sigarco = new subarco(ficticio);
                } else {
                    // Si ya existe el predecesor
                    if (temp->destino->destino == NULL)
                        // Nuevo destino agregado
                        temp->destino->destino = nvert;
                    else {
                        // Buscar el destino existente y agregar un ficticio
                        vertice *tvert = temp->destino->destino;

                        arco *ficticio = new arco("Fict.", 0);
                        ficticio->destino = nvert;
                        agregararco(ficticio);

                        // Insertar el nuevo arco ficticio en el vertice
                        subarco *nsarco = new subarco(ficticio);
                        if (tvert->sigarco == NULL)
                            tvert->sigarco = nsarco;
                        else {
                            subarco *subtemp = tvert->sigarco;
                            while (subtemp->sig != NULL)
                                subtemp = subtemp->sig;
                            subtemp->sig = nsarco;
                        }
                    }
                }
                temp = temp->sig;
            }
            // Agregar el nuevo arco a la lista del vertice
            subarco *nuevosa = new subarco(nuevo);
            nvert->sigarco = nuevosa;
            // Agregar arco a la lista general
            agregararco(nuevo);
        } else {
            // En el caso de que ya exista un vertice que cubra los preds
            // Se agrega el arco a la lista del vertice
            subarco *nuevosa = new subarco(nuevo);
            if (vpred->sigarco == NULL)
                vpred->sigarco = nuevosa;
            else {
                subarco *temp = vpred->sigarco;
                while (temp->sig != NULL)
                    temp = temp->sig;
                temp->sig = nuevosa;
            }
            // Agregar arco a la lista general
            agregararco(nuevo);
        }
    }
}

// Indica el vertice que sea predecesor de la lista dada
grafo::vertice *grafo::espredecesor(subarco *lista) {
    vertice *resultado = NULL, *temp = vertinicio;
    if (lista != NULL) {
        // Se recorre la lista de vertices
        while (temp != NULL) {
            // Se pregunta por la cantidad de cada uno
            if (totalpreds(temp->pred) == totalpreds(lista)) {

                // Cada arco esta cubierto hasta que se demuestre lo contrario
                bool todoscubiertos = true;
                subarco *tsarco = lista;

                // Se recorre la lista de predecesores de la lista
                while (tsarco != NULL) {
                    bool cubierto = false;
                    // Se recorre la lista de predecesores del vertice actual
                    subarco *vertpred = temp->pred;
                    while (vertpred != NULL) {
                        // Al encontrar la coincidencia se marca "cubierto"
                        if (vertpred->destino == tsarco->destino) {
                            cubierto = true;
                            break;
                        }
                        vertpred = vertpred->sig;
                    }
                    // Si no se cubrio el pred. no estan todos cubiertos
                    if (!cubierto) {
                        todoscubiertos = false;
                        break;
                    }
                    tsarco = tsarco->sig;
                }
                // Si se encontro el vertice, se devuelve
                if (todoscubiertos)
                    return temp;
            }
            temp = temp->sig;
        }
    }
    return resultado;
}

// Devuelve el total de elementos de una sublista
int grafo::totalpreds(subarco *lista) {
    if (lista == NULL)
        return 0;
    else {
        subarco *temp = lista;
        int cuenta = 0;
        // Cada elemento suma uno mas
        while (temp != NULL) {
            cuenta++;
            temp = temp->sig;
        }
        return cuenta;
    }
}

// Cambiar el tiempo de un arco, segun su nombre
bool grafo::modificartiempo(string nombre, int ntiempo) {

    // Convertir el texto a char[]
    char texto[20];
    int tamano = nombre.copy(texto, 20, 0);
    texto[tamano] = '\0';

    // Buscar el arco en la lista
    arco *arcob = buscar(texto);
    if (arcob != NULL)
        // Si se encuentra, se modifica el valor
        arcob->tiempo = ntiempo;
    else
        return false;
    return true;

}

void grafo::cpm() {
    // Calcular el ET usando la forma directa
    cmps = 0; asgs = 0; lns = 0;
    limpiaret();
    calcet(NULL, vertinicio, 0, true);
    rutacrit("", vertinicio, 0);
}

void grafo::pert() {
    // Calcular el ET usando la formula especifica
    cmps = 0; asgs = 0; lns = 0;
    limpiaret();
    calcet(NULL, vertinicio, 0, false);
    rutacrit("", vertinicio, 0);
}

/* Calcular el ET del grafo.
   directo: indica si se utiliza la formula de PERT o si se
   calcula directamente con el tiempo.
   Se miden las asignaciones, comparaciones y lineas del metodo
   en si. calcet calcula tambien la ruta critica, pero las lineas
   que se necesitan para ello no se consideran en las medidas.
*/
void grafo::calcet(arco *origen, vertice *vert, double tiempo, bool directo) {

    cmps++; lns++;
    // Buscar el menor tiempo
    if (vert->et < tiempo) {
        asgs++; lns++;
        if (directo)
            // Usar la forma directa de CPM
            vert->et = tiempo;
        else {
            asgs++; lns++;
            // Usar la formula de PERT
            vert->et = (0.30 * tiempo + 4 * tiempo + 0.40 * tiempo) / 6;
        }
    }
    asgs++; lns++;
    // Revisar la lista de arcos sucesores
    subarco *temp = vert->sigarco;
    while (temp != NULL) {
        cmps++;
        calcet(temp->destino, temp->destino->destino,
               tiempo + temp->destino->tiempo, directo);
        asgs++; lns += 3;
        temp = temp->sig;
    }
    cmps++; lns++;
}

// Calcular la ruta critica
void grafo::rutacrit(string rc, vertice *vert, double tiempo) {
    if (vert->sigarco == NULL) {
        // Se devuelve lo que se tiene al llegar al vertice final
        rutac = rc + "Ruta Critica";
    } else {
        // Recorrer sublista de sucesores
        subarco *sucs = vert->sigarco;
        while (sucs != NULL) {
            // Considerar solo aquellos que producen el et del destino
            if (sucs->destino->tiempo + tiempo == sucs->destino->destino->et) {
                string aux = rc;
                if (sucs->destino->tiempo != 0)
                    aux = aux.append(sucs->destino->nombre) + " - ";
                rutacrit(aux, sucs->destino->destino, sucs->destino->tiempo + tiempo);
            }
            sucs = sucs->sig;
        }
    }
}

// Agregar el valor 0 al ET de cada vertice
void grafo::limpiaret() {
    vertice *temp = vertinicio;
    while (temp != NULL) {
        temp->et = 0;
        temp = temp->sig;
    }
}
