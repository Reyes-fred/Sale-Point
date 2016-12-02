#include "informacionventa.h"
#include "ui_informacionventa.h"
#include "descuento.h"
#include "ui_descuento.h"
#include "apartadoventa.h"
#include "ui_apartadoventa.h"
#include <QMessageBox>
#include <QDebug>
InformacionVenta::InformacionVenta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformacionVenta)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);
}


InformacionVenta::~InformacionVenta()
{
    delete ui;
}
void InformacionVenta::SetTotal(QString tot){
    total = tot;
    ui->label_4->setText(total);
}

void InformacionVenta::on_pushButton_clicked()
{
    this->close();
}

void InformacionVenta::on_pushButton_2_clicked()
{
    Descuento des;
    des.setModal(true);
    des.setdes(ui->label_4->text());
    des.exec();
    ui->label_4->setText(des.ui->label_5->text());
}

void InformacionVenta::on_pushButton_3_clicked()
{
    this->close();
    apartadoVenta apa;
    apa.setModal(true);
    apa.settotal(ui->label_4->text());
    apa.exec();
}

void InformacionVenta::on_pushButton_4_clicked()
{   if(ui->lineEdit->text()!=""){
    if(calcularCosto()==true){
    ven.nuevaVenta(ui->label_4->text(),"0");

    for(int x=0;x<colum;x++){
    in.descontar(nombre[x],cantidad[x]);
    }
    }
    }

}

void InformacionVenta::Descontar(QString nom[],QString can[],int tot){
    nombre=new QString[tot];cantidad=new QString[tot];
    for(int x=0;x<tot;x++){
    nombre[x]=nom[x];
    cantidad[x]=can[x];
    }
    colum=tot;

}


bool InformacionVenta::calcularCosto(){

    QString costotot;
    float costof,totalVen,ingre;
    ingre = ui->lineEdit->text().toFloat();
    costof = ui->label_4->text().toFloat();
    if(ingre>=costof){
    totalVen = ingre-costof;
    costotot = QString::number(totalVen);
    QMessageBox::information(0, "", "Cambio:  "+costotot);
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    return true;}
    ui->lineEdit->setText("");
    return false;
}
