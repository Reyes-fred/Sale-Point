#include "persona.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

persona::persona()
{
}

bool persona::autentificarse(QString nom, QString pass){
    QFile file("archivos\\login.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       qDebug() << "Error";

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        if(campo[0]==nom && campo[1]==pass)
          {return true;}
       }
     file.close();

return false;
}
bool persona::buscarUsuario(QString nom){

    QFile file("archivos\\personas.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
         if(campo[0]==nom)
          {return true;}
       }
     file.close();
return false;
}

bool persona::buscarUsuario(QString nom,QString app){

    QFile file("archivos\\personas.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
     while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
          if(campo[0]==nom&&campo[1]==app)
          {return true;}
       }
     file.close();
return false;
}
