#include "contabilidad.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
contabilidad::contabilidad()
{
}

void contabilidad::apartar(QString nom,QString ape,QString domicilio,QString total,QString fecha){
    venta ve;
    QString folio = ve.nuevoFolioApar();
    QString line="";
    QFile file("archivos\\apartados.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
           QMessageBox::information(0, "Error", file.errorString());
        else{
        QTextStream in(&file);
            in<<folio<<","<<nom<<","<<ape<<","<<domicilio<<","<<total<<","<<fecha<<"\n";}
         file.close();
}



void contabilidad::abonar(QString nom,QString ape,QString abono){
    QString line="",total;
    QFile file("archivos\\apartados.txt");
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

                  if(campo[1]==nom&&campo[2]==ape)
                  {
                      in2<<campo[0]<<","<<campo[1]<<","<<campo[2]<<","<<campo[3]<<","<<abono<<","<<campo[5]<<"\n";
                  }

                  else{
                      in2<<line<<endl;
                  }
               }
            file2.close();
            file.close();
            file.remove("archivos\\apartados.txt");
            file2.rename("archivos\\apartados.txt");

}


QString contabilidad::getAcuenta(QString nom,QString ape){
    QString line="";
    QFile file("archivos\\apartados.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList campo = line.split(",");
              if(campo[1]==nom&&campo[2]==ape){
              return campo[4];}
              else{line="";}
           }
         file.close();


    return line;

}

void contabilidad::liberarcuenta(QString nom,QString ape){
    QString line="",total;
    QFile file("archivos\\apartados.txt");
    QFile file2("archivos\\temp.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());
        if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file2.errorString());

        QTextStream in(&file);
        QTextStream in2(&file2);

        while (!in.atEnd()) {
                line = in.readLine();
                QStringList campo = line.split(",");

                  if(campo[1]!=nom&&campo[2]!=ape)
                  {
                      in2<<line<<"\n";
                  }

               }
            file2.close();
            file.close();
            file.remove("archivos\\apartados.txt");
            file2.rename("archivos\\apartados.txt");
}

