#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <QString>
#include "producto.h"
class inventario
{

public:
    inventario();
    producto pro;
    QString buscarProducto(QString);
    void descontar(QString,QString);
};

#endif // INVENTARIO_H
