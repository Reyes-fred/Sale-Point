#include "nuevousuario.h"
#include "ui_nuevousuario.h"
#include "persona.h"
#include "empleado.h"
nuevoUsuario::nuevoUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nuevoUsuario)
{
    ui->setupUi(this);
}

nuevoUsuario::~nuevoUsuario()
{
    delete ui;
}
void nuevoUsuario::limpiar(){
    ui->apel->setText(""); ui->dom->setText("");
    ui->eda->setText(""); ui->ema->setText("");
    ui->fena->setText(""); ui->nom->setText("");
    ui->suel->setText(""); ui->tel->setText("");
    ui->con->setText(""); ui->usu->setText("");

}

void nuevoUsuario::on_pushButton_clicked()
{
    if(per.buscarUsuario(ui->nom->text(),ui->apel->text())==false){
    emp.nuevoUsuario(ui->nom->text(),ui->apel->text(),ui->ema->text(),ui->eda->text(),ui->con->text(),ui->tel->text(),ui->usu->text(),ui->dom->text(),ui->suel->text(),ui->fena->text());
    limpiar();
    }

}

void nuevoUsuario::on_pushButton_2_clicked()
{
    limpiar();

}

void nuevoUsuario::on_pushButton_3_clicked()
{
    this->close();
}
