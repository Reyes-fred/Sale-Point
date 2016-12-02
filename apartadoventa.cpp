#include "apartadoventa.h"
#include "ui_apartadoventa.h"
#include <QDebug>
apartadoVenta::apartadoVenta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::apartadoVenta)
{
    ui->setupUi(this);
}

apartadoVenta::~apartadoVenta()
{
    delete ui;
}

void apartadoVenta::on_pushButton_2_clicked()
{
    this->close();


}

void apartadoVenta::on_pushButton_clicked()
{
    if(ui->lineEdit->text()!="" && ui->lineEdit_3->text()!="" && ui->lineEdit_2->text()!=""){
        ven.apartar(ui->lineEdit->text(),ui->lineEdit_3->text(),ui->lineEdit_2->text(),total,fe.getFecha());
        ven.nuevaVenta(total,"1");
        this->close();
    }
}

void apartadoVenta::settotal(QString tot){
    total=tot;
}
