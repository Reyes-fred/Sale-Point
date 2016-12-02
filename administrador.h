#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include "persona.h"
class administrador:public persona
{
public:
    administrador();
    void administrarproducto();
    void administrarVentas();
    void eliminarProducto();
    void nuevoProducto();
    void verDetalleVenta();

};

#endif // ADMINISTRADOR_H
