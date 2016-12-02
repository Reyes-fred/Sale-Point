#include "fecha.h"
#include <QTime>
fecha::fecha()
{
}

QString fecha::getHora(){
    return QTime::currentTime().toString();
}

QString fecha::getFecha(){
    return QDate::currentDate().toString();
}
