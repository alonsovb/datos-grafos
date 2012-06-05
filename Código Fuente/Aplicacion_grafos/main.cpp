#include <QtGui/QApplication>
#include "aplicacion_grafos.h"
#include <iostream>

// Fecha de inicio: 10 Abril, 2011.
// Fecha de ultima modificacion: 27 Abril, 2011.

int main(int argc, char *argv[])
{
    if (argc > 0)
        cout << argv[0];
    QApplication a(argc, argv);
    Aplicacion_grafos w;
    w.show();

    return a.exec();
}
