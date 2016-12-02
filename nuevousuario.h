#ifndef NUEVOUSUARIO_H
#define NUEVOUSUARIO_H
#include "persona.h"
#include "empleado.h"
#include <QDialog>

namespace Ui {
class nuevoUsuario;
}

class nuevoUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoUsuario(QWidget *parent = 0);
    ~nuevoUsuario();
    persona per;
    empleado emp;
    void limpiar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::nuevoUsuario *ui;
};

#endif // NUEVOUSUARIO_H
