#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>
#include "persona.h"
class cliente:public persona
{
private:
    QString direccion;
public:
    cliente();
    bool validarUsuario(QString,QString);
    QString getDetalles(QString,QString);
    QString getDireccion();
    void setDireccion(QString);

};

#endif // CLIENTE_H
