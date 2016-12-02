#include "cliente.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
cliente::cliente()
{
}

bool cliente::validarUsuario(QString nom,QString ape){
    QString line="";
    QFile file("archivos\\apartados.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList campo = line.split(",");
              if(campo[1]==nom&&campo[2]==ape){
              return true;}
           }
         file.close();


    return false;
}

QString cliente::getDetalles(QString nom,QString ape){
    QString line="";
    QFile file("archivos\\apartados.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();

            QStringList campo = line.split(",");
                if(campo[1]==nom && campo[2]==ape){

                    return line;
              }
                else {line="";}
           }
         file.close();
         return line;

}
