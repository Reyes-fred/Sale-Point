#include "login.h"
#include "ui_login.h"
#include "persona.h"
#include "ventanaventa.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{

    ui->setupUi(this);
    ui->dpass->setEchoMode(QLineEdit::Password);
    ui->dpass->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    intentos=0;
}

login::~login()
{
    delete ui;
}

void login::setPass(QString newpass)
{
 pass=newpass;
}
void login::setusuario(QString us)
{
 usuario=us;
}
QString login::getPass(){
    return pass;
}
QString login::getusuario(){
    return usuario;
}
bool login::autentificar(QString nom,QString pass){
    bool activo=false;
    persona a;
    activo = a.autentificarse(nom,pass);
    return activo;
}
void login::on_pushButton_clicked()
{
}

void login::on_boton_clicked()
{
    setusuario(ui->dusuario->text());
    setPass(ui->dpass->text());
    if(autentificar(getusuario(),getPass())==true){
      this->close();
      VentanaVenta principal;
      principal.setModal(true);
      principal.exec();
    }
    else{
        ui->dusuario->setText("");
        ui->dpass->setText("");
        intentos++;}
    if(intentos==3){
        this->close();
    }
}

