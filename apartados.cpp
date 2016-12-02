#include "apartados.h"
#include "ui_apartados.h"
#include <QDebug>
Apartados::Apartados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apartados)
{
    ui->setupUi(this);
    cargar();
}

Apartados::~Apartados()
{
    delete ui;
}

void Apartados::on_pushButton_clicked()
{
   QString line = cli.getDetalles(ui->lineEdit->text(),ui->lineEdit_2->text());

   if(line!=""){
       ui->tableWidget->clearContents();
       QStringList campo = line.split(",");
       for(int y=0;y<campo.length();y++){
         ui->tableWidget->setItem(0,y,new QTableWidgetItem(campo[y]));
       }
   }


}

void Apartados::cargar(){
    int x=0;
    QStringList labels;
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(1);
    labels <<"Folio"<<"Nombre"<<"Apellido"<<"Direccion"<<"Adeudo"<<"Fecha";
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    QFile file("archivos\\apartados.txt");
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
        ui->tableWidget->insertRow(x);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    }
     file.close();

}

void Apartados::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
    cargar();
}

void Apartados::on_pushButton_3_clicked()
{
  QString faltante;
    if(ui->lineEdit_2->text()!=""&&ui->lineEdit_2->text()!=""&&ui->lineEdit_3->text()!=""){
        faltante=ven.abono(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
            if(faltante!=""){QMessageBox::information(0, "", "Resta:  "+faltante);
            cargar();
            ui->lineEdit->setText("");
            ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            }
    }
}
