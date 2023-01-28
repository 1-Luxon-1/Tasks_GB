#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double side1 = ui->line_side1->text().toDouble();
    double side2 = ui->line_side2->text().toDouble();
    double angle = ui->line_angle->text().toDouble();
    if(ui->radio_but_rad->isChecked())
    {
        ui->line_side3_result->setText(QString::number(qSqrt(qPow(side1,2)+qPow(side2,2)-2*side1*side2*qCos(angle))));
    }
    else
    {
        angle *= (3.14/180);
        ui->line_side3_result->setText(QString::number(qSqrt(qPow(side1,2)+qPow(side2,2)-2*side1*side2*qCos(angle))));
    }
}

