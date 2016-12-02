#ifndef APARTADOS_H
#define APARTADOS_H
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDialog>
#include "venta.h"
#include "cliente.h"

namespace Ui {
class Apartados;
}

class Apartados : public QDialog
{
    Q_OBJECT

public:
    explicit Apartados(QWidget *parent = 0);
    ~Apartados();
    void cargar();
    venta ven;
    cliente cli;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Apartados *ui;
};

#endif // APARTADOS_H
