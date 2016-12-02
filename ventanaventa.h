#ifndef VENTANAVENTA_H
#define VENTANAVENTA_H

#include <QDialog>
#include "producto.h"

namespace Ui {
class VentanaVenta;
}

class VentanaVenta : public QDialog
{
    Q_OBJECT

public:
    producto pro;
    QString *nom,*can;
    void Descontar();
    void refresh();
    Ui::VentanaVenta *ui;
    int cont;
    explicit VentanaVenta(QWidget *parent = 0);
    ~VentanaVenta();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void agregarProducto(QString);
    void TotalParcial();
    void limpiar();
    void on_tableWidget_2_cellChanged(int row, int column);

    void on_pushButton_2_clicked();



    void on_pushButton_4_clicked();
    void on_pushButton_7_clicked();
    void on_lineEdit_returnPressed();
};

#endif // VENTANAVENTA_H
