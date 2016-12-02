#ifndef PANCONTA_H
#define PANCONTA_H

#include <QDialog>

namespace Ui {
class PanConta;
}

class PanConta : public QDialog
{
    Q_OBJECT

public:
    void refresh();
    void getIngresos();
    explicit PanConta(QWidget *parent = 0);
    ~PanConta();

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::PanConta *ui;
};

#endif // PANCONTA_H
