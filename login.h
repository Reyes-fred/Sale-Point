#ifndef LOGIN_H
#define LOGIN_H
#include "persona.h"
#include <QDialog>
#include <QString>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void setusuario(QString);
    void setPass(QString);
    QString getusuario();
    QString getPass();
    bool autentificar(QString,QString);

private slots:
    void on_pushButton_clicked();

    void on_boton_clicked();

private:
    Ui::login *ui;
    QString usuario,pass;
    int intentos;
};

#endif // LOGIN_H
