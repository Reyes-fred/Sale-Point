#ifndef CONTABILIDAD_H
#define CONTABILIDAD_H
#include "venta.h"
class contabilidad
{
public:
    contabilidad();
    void apartar(QString,QString,QString,QString,QString);
    void abonar(QString,QString,QString);
    QString getAcuenta(QString,QString);
    void liberarcuenta(QString,QString);
};

#endif // CONTABILIDAD_H
