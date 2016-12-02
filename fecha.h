#ifndef FECHA_H
#define FECHA_H
#include <QString>
class fecha
{
private:
    QString fechaM,hora;
public:
    fecha();
    QString getFecha();
    QString getHora();
    void setFecha(QString);
    void setHora(QString);
};

#endif // FECHA_H
