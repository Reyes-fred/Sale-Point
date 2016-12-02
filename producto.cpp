#include "producto.h"
#include <qfile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
producto::producto()
{
}

QString producto::getDetalles(QString nom){
    int x=0;
    QString line="";
    QFile file("archivos\\productos.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList campo = line.split(",");
      if(campo[1]==nom){
            return line;
        }
      else{line="";}
        x++;
    }
     file.close();
    return line;
}

QString producto::getDetalles(QString id,int i){
    int x=0;
    QString line="";
    QFile file("archivos\\productos.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList campo = line.split(",");
      if(campo[0]==id){
            return line;
        }
      else{line="";}
        x++;
    }
     file.close();
    return line;

}
