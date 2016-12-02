#ifndef DESCUENTO_H
#define DESCUENTO_H
#include <QString>
#include <QDialog>

namespace Ui {
class Descuento;
}

class Descuento : public QDialog
{
    Q_OBJECT

public:
    explicit Descuento(QWidget *parent = 0);
    ~Descuento();
    QString desc;
    void setdes(QString);

    Ui::Descuento *ui;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();


    void on_lineEdit_textChanged(const QString &arg1);

private:

};

#endif // DESCUENTO_H
