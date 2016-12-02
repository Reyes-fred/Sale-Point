#include "descuento.h"
#include "ui_descuento.h"

Descuento::Descuento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Descuento)
{
    ui->setupUi(this);
    ui->label_5->setText("");
}

Descuento::~Descuento()
{
    delete ui;
}

void Descuento::on_pushButton_2_clicked()
{
    ui->label_5->setText(ui->label_4->text());
    this->close();
}

void Descuento::on_pushButton_clicked()
{
    if(ui->lineEdit->text()!=""){
    float des=ui->lineEdit->text().toFloat();
    float tot=desc.toFloat();
    if(des<tot){
    float total=tot-((tot*des)/100);
    QString totalpan=QString::number(total);
    this->close();

    }
    else{
        ui->lineEdit->setText("");
    }}


}

void Descuento::setdes(QString descu){
    desc=descu;
    ui->label_4->setText(desc);
}
void Descuento::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text()!=""){
    float des=ui->lineEdit->text().toFloat();
    float tot=desc.toFloat();
    if(des<tot){
    float total=tot-((tot*des)/100);
    QString totalpan=QString::number(total);
    ui->label_5->setText(totalpan);}
    else{
        ui->lineEdit->setText("");
    }}
}
