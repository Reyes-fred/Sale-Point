#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <QString>
#include "persona.h"
class empleado:public persona
{
private :
    QString domicilio,fechaIngreso,fechaNacimiento,sueldo;

public:
   empleado();
   QString getDomicilio();
   QString getFechaIngreso();
   QString getFechaNacimiento();
   QString getSueldo();
   QString getDetalles(QString);
   void setDomicilio(QString);
   void setFechaIngreso(QString);
   void setFechaNacimiento(QString);
   void setSueldo(float);
   bool nuevoUsuario(QString,QString,QString,QString, QString,QString,QString,QString,QString,QString);
   void eliminarUsuario(QString);
};

#endif // EMPLEADO_H
