#ifndef TIENDA_H
#define TIENDA_H
#include <QString>
class tienda
{
private:
    QString direccion,nombre,telefono;
public:
    tienda();
    QString getDireccion();
    QString getNombre();
    QString getTelefono();
    void setDireccion(QString);
    void setNombre(QString);
    void setTelefono(QString);
};

#endif // TIENDA_H
