#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <QString>
class producto
{
private:
    QString descripcion;
    int existencia,id;
    double precio;
public:
    producto();
    QString getDetalles(QString);
    QString getDetalles(QString,int);
    QString getDescripcion();
    int getExistencia();
    int getId();
    double getPrecio();
    void setDescripcion(QString);
    void setExistencia(int);
    void setId(int);
    void setPrecio(double);
};

#endif // PRODUCTO_H
