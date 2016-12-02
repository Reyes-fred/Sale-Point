
#include "editarusuario.h"
#include "ui_editarusuario.h"

editarUsuario::editarUsuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarUsuario)
{
    ui->setupUi(this);

}

editarUsuario::~editarUsuario()
{
    delete ui;
}
void editarUsuario::limpiar(){
    ui->apel->setText(""); ui->dom->setText("");
    ui->eda->setText(""); ui->ema->setText("");
    ui->fena->setText(""); ui->nom->setText("");
    ui->suel->setText(""); ui->tel->setText("");
    ui->con->setText(""); ui->usu->setText("");

}

void editarUsuario::iniciar(QString nom){
    QString line = emp.getDetalles(nom);
    QStringList campo = line.split(",");
    ui->apel->setText(campo[1]); ui->dom->setText(campo[7]);
    ui->eda->setText(campo[3]); ui->ema->setText(campo[2]);
    ui->fena->setText(campo[9]); ui->nom->setText(campo[0]);
    ui->suel->setText(campo[8]); ui->tel->setText(campo[4]);
    ui->con->setText(campo[6]); ui->usu->setText(campo[5]);
}

void editarUsuario::on_pushButton_2_clicked()
{
    limpiar();
}

void editarUsuario::on_pushButton_3_clicked()
{
    this->close();
}

void editarUsuario::on_pushButton_clicked()
{
    emp.eliminarUsuario(ui->nom->text());
    emp.nuevoUsuario(ui->nom->text(),ui->apel->text(),ui->ema->text(),ui->eda->text(),ui->con->text(),ui->tel->text(),ui->usu->text(),ui->dom->text(),ui->suel->text(),ui->fena->text());
    limpiar();
}
