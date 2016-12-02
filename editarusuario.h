#ifndef EDITARUSUARIO_H
#define EDITARUSUARIO_H

#include <QDialog>
#include "empleado.h"
namespace Ui {
class editarUsuario;
}

class editarUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit editarUsuario(QWidget *parent = 0);
    ~editarUsuario();
    void iniciar(QString);
    void limpiar();
    empleado emp;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::editarUsuario *ui;


};

#endif // EDITARUSUARIO_H
