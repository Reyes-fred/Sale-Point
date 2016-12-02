#ifndef PROVEEDOR_H
#define PROVEEDOR_H
#include <QString>

class proveedor
{
private:
   QString email,descripcion,nombre,telefono;
public:
    proveedor();
    void eliminarProveedor(QString);
    void nuevoProveedor(QString,QString,QString,QString);
    void setCorreo(QString);
    void setDescripcion(QString);
    void setNombre(QString);
    void setTelefono(QString);
    QString getCorreo();
    QString getDescripcion();
    QString getNombre();
    QString getTelefono();

};

#endif // PROVEEDOR_H
