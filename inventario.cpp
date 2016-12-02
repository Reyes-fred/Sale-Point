#include "inventario.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

inventario::inventario()
{
}
void inventario::descontar(QString nom,QString cant){
    QStringList campo;
    int ban=0;
    QFile file("archivos\\productos.txt");
    QFile file2("archivos\\temp.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    QTextStream in2(&file2);
    while (!in.atEnd()) {
        QString line = in.readLine();
        campo = line.split(",");
        for(int y=0;y<campo.length();y++){
            if(campo[y]==nom){
                campo[3]= QString::number(campo[3].toInt()-cant.toInt());
                ban=1;
            }
         }
         if(ban=0){
             in2<<line<<endl;
         }
         else{
             for(int y=0;y<campo.length();y++){
                 if(y==campo.length()-1){in2<<campo[y];}
                 else{
                 in2<<campo[y]<<",";}
              }
             in2<<endl;
             ban=0;
         }

    }
    file2.close();
    file.close();
    file.remove("archivos\\productos.txt");
    file2.rename("archivos\\productos.txt");


}




QString inventario::buscarProducto(QString id){
    QString linea;
    linea = pro.getDetalles(id,1);
    return linea;
}
