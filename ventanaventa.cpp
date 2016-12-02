#include "ventanaventa.h"
#include "ui_ventanaventa.h"
#include "usuarios.h"
#include "ui_usuarios.h"
#include "informacionventa.h"
#include "ui_informacionventa.h"
#include "panconta.h"
#include "ui_panconta.h"
#include "apartados.h"
#include "ui_apartados.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include "producto.h"

VentanaVenta::VentanaVenta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaVenta)
{   cont=0;
    ui->setupUi(this);
    ui->label_4->setText("");
    int x=0;
    QStringList labels,labels2;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget_2->setColumnCount(4);
    ui->tableWidget_2->setRowCount(1);
    labels <<"ID"<<"Nombre"<<"Precio"<<"Existencia";
    labels2<<"ID"<<"Nombre"<<"Precio"<<"Cantidad";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->tableWidget_2->setHorizontalHeaderLabels(labels2);
    QFile file("archivos\\productos.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        for(int y=0;y<campo.length()-1;y++){
          ui->tableWidget->setItem(x,y,new QTableWidgetItem(campo[y]));
        }
        x++;
        ui->tableWidget->insertRow(x);
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
     file.close();
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     InformacionVenta info;
}

VentanaVenta::~VentanaVenta()
{
    delete ui;
}

void VentanaVenta::on_pushButton_3_clicked()
{
    usuarios usu;
    usu.setModal(true);
    usu.exec();

}

void VentanaVenta::on_pushButton_clicked()
{   if(cont!=0){
    InformacionVenta info;
    info.setModal(true);
    info.SetTotal(ui->label_4->text());
    Descontar();
    info.Descontar(nom,can,cont);
    info.exec();
    limpiar();
    refresh();
    cont=0;
    ui->label_4->setText("");

    }

}
void VentanaVenta::Descontar(){
    nom=new QString[cont];can=new QString[cont];
    for(int x=0;x<cont;x++){
        nom[x]=ui->tableWidget_2->item(x,1)->text();
        can[x]=ui->tableWidget_2->item(x,3)->text();
    }
}


void VentanaVenta::on_pushButton_5_clicked()
{
    PanConta conta;
    conta.setModal(true);
    conta.exec();

}

void VentanaVenta::on_pushButton_6_clicked()
{
    Apartados apar;
    apar.setModal(true);
    apar.exec();
    limpiar();
}

void VentanaVenta::on_tableWidget_doubleClicked(const QModelIndex &index)
{ QString text;
    if(index.column()==1){
  text = ui->tableWidget->item(index.row(), index.column())->text();
  agregarProducto(text);
    }
}

void VentanaVenta::agregarProducto(QString nom){
    int y;
    if(cont!=0){
   ui->tableWidget_2->insertRow(cont);
   }
    QString text;
   text = pro.getDetalles(nom);
   QStringList campo = text.split(",");
   for(y=0;y<3;y++){
     ui->tableWidget_2->setItem(cont,y,new QTableWidgetItem(campo[y]));
    ui->tableWidget_2->resizeColumnsToContents();
   }
    ui->tableWidget_2->setItem(cont,y,new QTableWidgetItem("1"));
cont++;
    TotalParcial();
}

void VentanaVenta::TotalParcial(){
    float costo=0,precio;
    int cant;
    QString text,text2;

    for(int x=0;x<cont;x++){
    text = ui->tableWidget_2->item(x, 2)->text();
    text2 = ui->tableWidget_2->item(x, 3)->text();
    precio=text.toFloat();
    cant=text2.toInt();
    costo+=(precio*cant);
    }
    text = QString::number(costo);
    ui->label_4->setText(text);
}

void VentanaVenta::on_tableWidget_2_cellChanged(int row, int column)
{
    TotalParcial();

}

void VentanaVenta::on_pushButton_2_clicked()
{
    limpiar();
}
void VentanaVenta::limpiar(){

        QStringList labels2;
        labels2<<"ID"<<"Nombre"<<"Precio"<<"Cantidad";
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setHorizontalHeaderLabels(labels2);
        ui->label_4->setText("");
        cont=0;
}
void VentanaVenta::refresh(){
    int x=0;
    QStringList labels;
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(1);
    labels <<"ID"<<"Nombre"<<"Precio"<<"Existencia";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    QFile file("archivos\\productos.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        for(int y=0;y<campo.length()-1;y++){
          ui->tableWidget->setItem(x,y,new QTableWidgetItem(campo[y]));
        }
        x++;
        ui->tableWidget->insertRow(x);
        ui->tableWidget->resizeColumnsToContents();
    }
     file.close();
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void VentanaVenta::on_pushButton_4_clicked()
{

    inventario inv;
    QString linea;
   linea =  inv.buscarProducto(ui->lineEdit->text());
   if(linea!=""){
       ui->tableWidget->clear();
       QStringList campo = linea.split(",");
       for(int y=0;y<campo.length()-1;y++){
         ui->tableWidget->setItem(0,y,new QTableWidgetItem(campo[y]));
       }
   }
   else {
     QMessageBox::information(0, "Error", "Producto No disponible");
   }

}

void VentanaVenta::on_pushButton_7_clicked()
{
    refresh();
    ui->lineEdit->setText("");
}

void VentanaVenta::on_lineEdit_returnPressed()
{
    inventario inv;
    QString linea;
   linea =  inv.buscarProducto(ui->lineEdit->text());
   if(linea!=""){
       ui->tableWidget->clear();
       QStringList campo = linea.split(",");
       for(int y=0;y<campo.length()-1;y++){
         ui->tableWidget->setItem(0,y,new QTableWidgetItem(campo[y]));
       }
   }
   else {
     QMessageBox::information(0, "Error", "Producto No disponible");
   }
}
