#ifndef INFORMACIONVENTA_H
#define INFORMACIONVENTA_H
#include "venta.h"
#include "fecha.h"
#include "contabilidad.h"
#include "inventario.h"
#include "ventanaventa.h"
#include "ui_ventanaventa.h"
#include <QDialog>
#include <QString>
namespace Ui {
class InformacionVenta;
}

class InformacionVenta : public QDialog
{
    Q_OBJECT

public:
    explicit InformacionVenta(QWidget *parent = 0);
    ~InformacionVenta();
    void SetTotal(QString);
    bool calcularCosto();
   venta ven;
    fecha fe;
    contabilidad con;
    inventario in;
    QString total;
    QString *nombre,*cantidad;
    int colum;
    void Descontar(QString[],QString[],int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::InformacionVenta *ui;
};

#endif // INFORMACIONVENTA_H
