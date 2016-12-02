#ifndef APARTADOVENTA_H
#define APARTADOVENTA_H
#include "venta.h"
#include "fecha.h"
#include <QDialog>

namespace Ui {
class apartadoVenta;
}

class apartadoVenta : public QDialog
{
    Q_OBJECT

public:
    explicit apartadoVenta(QWidget *parent = 0);
    ~apartadoVenta();
    venta ven;
    fecha fe;
    QString total;
    void settotal(QString);


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::apartadoVenta *ui;
};

#endif // APARTADOVENTA_H
