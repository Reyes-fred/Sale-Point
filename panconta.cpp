#include "panconta.h"
#include "ui_panconta.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

PanConta::PanConta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PanConta)
{
    ui->setupUi(this);
    ui->label_2->setText("");
    ui->label_5->setText("");
    refresh();
    getIngresos();
}

PanConta::~PanConta()
{
    delete ui;
}

void PanConta::getIngresos(){
    int x=0;
    QString totalpanta;
    float total=0;
    QFile file("archivos\\venta.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       QMessageBox::information(0, "Error", file.errorString());
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList campo = line.split(",");
        total+=campo[1].toFloat();
        x++;
    }
     file.close();
     totalpanta = QString::number(total);
    ui->label_2->setText(totalpanta);

}

void PanConta::refresh(){
        int x=0;
        QStringList labels;
        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->setRowCount(1);
        labels <<"ID"<<"Total"<<"Fecha";
        ui->tableWidget->setHorizontalHeaderLabels(labels);
        QFile file("archivos\\venta.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           QMessageBox::information(0, "Error", file.errorString());

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList campo = line.split(",");
            for(int y=0;y<campo.length();y++){
              ui->tableWidget->setItem(x,y,new QTableWidgetItem(campo[y]));
            }
            x++;
            ui->tableWidget->insertRow(x);

        }
         file.close();
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


}
void PanConta::on_lineEdit_editingFinished()
{   QString total;
    float ingresos,egresos;
    ingresos = ui->label_2->text().toFloat();
    egresos = ui->lineEdit->text().toFloat();
    total = QString::number(ingresos-egresos);
    ui->label_5->setText(total);
}
