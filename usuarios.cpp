#include "usuarios.h"
#include "ui_usuarios.h"
#include "nuevousuario.h"
#include "ui_nuevoUsuario.h"
#include "editarusuario.h"
#include "ui_editarusuario.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
usuarios::usuarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usuarios)
{
    ui->setupUi(this);
    int x=0;
    QStringList labels;
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setRowCount(7);
    labels <<"Nombre"<<"Apellido"<<"Email"<<"Edad"<<"Telefono"<<"Usuario"<<"Contraseña"<<"Direccion"<<"Sueldo"<<"Fecha Nacimiento";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    QFile file("archivos\\personas.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        for(int y=0;y<campo.length();y++){
          ui->tableWidget->setItem(x,y,new QTableWidgetItem(campo[y]));
        }
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        x++;
    }
     file.close();
}

usuarios::~usuarios()
{
    delete ui;
}

void usuarios::on_pushButton_clicked()
{
          nuevoUsuario nuevo;
          nuevo.setModal(true);
          nuevo.exec();

}



void usuarios::on_pushButton_4_clicked()
{
ui->tableWidget->clear();
QStringList labels;
labels <<"Nombre"<<"Apellido"<<"Email"<<"Edad"<<"Telefono"<<"Usuario"<<"Contraseña"<<"Direccion"<<"Sueldo"<<"Fecha Nacimiento";
ui->tableWidget->setHorizontalHeaderLabels(labels);
 if(per.buscarUsuario(ui->lineEdit->text())==true){
    QString info = emp.getDetalles(ui->lineEdit->text());
    QStringList campo = info.split(",");
    for(int y=0;y<campo.length();y++){
    ui->tableWidget->setItem(0,y,new QTableWidgetItem(campo[y]));}
 }
 else
     QMessageBox::information(0, "", "No se Obtuvo Resultado");
    ui->lineEdit->setText("");
}


void usuarios::on_pushButton_2_clicked()
{
    QString text;
       text = ui->tableWidget->item(ui->tableWidget->currentRow(), ui->tableWidget->currentColumn())->text();
    emp.eliminarUsuario(text);
    ui->tableWidget->clear();
    QStringList labels;
    labels <<"Nombre"<<"Apellido"<<"Email"<<"Edad"<<"Telefono"<<"Usuario"<<"Contraseña"<<"Direccion"<<"Sueldo"<<"Fecha Nacimiento";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
}

void usuarios::on_pushButton_5_clicked()
{int x=0;
    QFile file("archivos\\personas.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        for(int y=0;y<campo.length();y++){
          ui->tableWidget->setItem(x,y,new QTableWidgetItem(campo[y]));
        }
        x++;
    }
     file.close();
}

void usuarios::on_pushButton_3_clicked()
{
    QString text;
       text = ui->tableWidget->item(ui->tableWidget->currentRow(), ui->tableWidget->currentColumn())->text();
    editarUsuario edit;
    edit.setModal(true);
    edit.iniciar(text);
    edit.exec();
}
