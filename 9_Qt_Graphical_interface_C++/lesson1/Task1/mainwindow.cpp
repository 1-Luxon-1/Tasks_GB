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


void MainWindow::on_button_calculate_clicked()
{
    double a = ui->line_coef_a->text().toDouble();
    double b = ui->line_coef_b->text().toDouble();
    double c = ui->line_coef_c->text().toDouble();
    QString strEquation = QString::number(a) + "x^2 + " + QString::number(b) + "x + " + QString::number(c) + " = " + "0";
    ui->lineEquation->setText(strEquation);

    double disc = (b * b) - 4*a*c;
    if(a == 0)
    {
        ui->line_x1->setText(QString::number((-c)/b));
        ui->line_x2->setText(QString::number((-c)/b));
    }
    else if(disc > 0)
    {
        ui->line_x1->setText(QString::number((-b - qSqrt(disc))/(2*a)));
        ui->line_x2->setText(QString::number((-b + qSqrt(disc))/(2*a)));
    }
    else if(disc == 0)
    {
        ui->line_x1->setText(QString::number((-b)/(2*a)));
        ui->line_x2->setText(QString::number((-b)/(2*a)));
    }
    else
    {
        QString i_x1 = "(" + QString::number(-b) + "+" + "i"+ QString::number(qSqrt(qAbs(disc))) + ")" + "/" + "2" + QString::number(a);
        QString i_x2 = "(" + QString::number(-b) + "-" + "i"+ QString::number(qSqrt(qAbs(disc))) + ")" + "/" + "2" + QString::number(a);
        ui->line_x1->setText(i_x1);
        ui->line_x2->setText(i_x2);
    }

}

