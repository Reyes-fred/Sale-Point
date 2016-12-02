#include "empleado.h"
#include "persona.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
empleado::empleado()
{
}
bool empleado::nuevoUsuario(QString nom,QString apel,QString email,QString eda,QString con,QString tel,QString usu,QString dom,QString suel,QString fena){
    QFile file("archivos\\personas.txt");
    QFile file2("archivos\\login.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
      return false;

    QTextStream in(&file);
    in<<nom<<","<<apel<<","<<email<<","<<eda<<","<<tel<<","<<usu<<","<<con<<","<<dom<<","<<suel<<","<<fena<<"\n";

   if(!file2.open(QIODevice::WriteOnly | QIODevice::Append))
       return false;

   QTextStream in2(&file2);
   in2<<usu<<","<<con<<","<<3<<"\n";
   file2.close();file.close();
return true;

}

QString empleado::getDetalles(QString nom){
    QString line="";
    QFile file("archivos\\personas.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList campo = line.split(",");

              if(campo[0]==nom)
              {return line;}
           }
         file.close();
    return line;

}

void empleado::eliminarUsuario(QString nom)
{
    QString line="";
    QString line2="";
    QFile file("archivos\\personas.txt");
    QFile file2("archivos\\temp.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());
        if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        QTextStream in2(&file2);
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList campo = line.split(",");

              if(campo[0]!=nom)
              {
                  in2<<line<<endl;
              }
           }
        file2.close();
        file.close();
        file.remove("archivos\\personas.txt");
        file2.rename("archivos\\personas.txt");
}
