#ifndef USUARIOS_H
#define USUARIOS_H
#include "persona.h"
#include "empleado.h"
#include <QDialog>

namespace Ui {
class usuarios;
}

class usuarios : public QDialog
{
    Q_OBJECT

public:
    explicit usuarios(QWidget *parent = 0);
    ~usuarios();
    void mostrar();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::usuarios *ui;
    persona per;
    empleado emp;
};

#endif // USUARIOS_H
