#ifndef VENTA_H
#define VENTA_H
#include <QString>
#include "cliente.h"
#include "contabilidad.h"
class venta
{
public:
    venta();
    int folio;
    double total;

public:
    cliente cli;

    double generarDescuento();
    void apartar(QString,QString,QString,QString,QString);
    QString abono(QString,QString,QString);
    void imprimir();
    void obtenerProducto();
    void setTotal(double);
    void nuevaVenta(QString,QString);
    QString nuevoFolio();
    QString nuevoFolioApar();
};

#endif // VENTA_H
