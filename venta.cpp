#include "venta.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QMessageBox>
venta::venta()
{
}
void venta::nuevaVenta(QString total, QString tipo){
    QString folio=nuevoFolio();
    QFile file("archivos\\venta.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    in<<folio<<","<<total<<","<<tipo<<"\n";
     file.close();

}

QString venta::nuevoFolio(){
    QStringList campo;
    QFile file("archivos\\venta.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        campo = line.split(",");
    }
    QString fo=campo[0];
    int folio= fo.toInt()+1;
    fo = QString::number(folio);
     file.close();
    return fo;
}

QString venta::nuevoFolioApar(){
    QStringList campo;
    QFile file("archivos\\apartados.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        campo = line.split(",");
    }
    QString fo=campo[0];
    int folio= fo.toInt()+1;
    fo = QString::number(folio);
     file.close();
    return fo;
}

void venta::apartar(QString nom,QString ape,QString domi,QString total,QString fecha){
    cliente cli;
    contabilidad con;

    if(cli.validarUsuario(nom,ape)!=true){
        con.apartar(nom,ape,domi,total,fecha);

    }
    else{
        QMessageBox::information(0, "", "Usuario Invalido");
    }


}

QString venta::abono(QString nom,QString ape,QString can){
    contabilidad con;
    QString tot,abonoap="";
    float total,canti,abono;
    canti = can.toFloat();
        if(cli.validarUsuario(nom,ape)==true){
                tot = con.getAcuenta(nom,ape);
                total = tot.toFloat();
                        if(canti<=total&&canti>0){
                            abono=total-canti;
                            abonoap=QString::number(abono);
                        con.abonar(nom,ape,abonoap);
                                if(abono==0){
                                    con.liberarcuenta(nom,ape);
                                    QMessageBox::information(0, "", "Cuenta Liquidada");
                                }
                                return abonoap;
                    }
        }
    else{
        QMessageBox::information(0, "", "Usuario Invalido");
    }
    return abonoap;
}
