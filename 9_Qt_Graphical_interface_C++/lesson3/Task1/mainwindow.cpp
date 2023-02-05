#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QFileDialog>

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


void MainWindow::on_buttonOpen_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty())
        return;
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        ui->plainTextEdit->setPlainText(text);
        file.close();
    }
}


void MainWindow::on_buttonSave_clicked()
{
    QString path = QFileDialog::getSaveFileName();
    QFile file(path);
    if(file.open((QIODevice::WriteOnly)))
    {
        QString text = ui->plainTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba,ba.length());
        file.close();
    }
}


void MainWindow::on_buttunHelp_clicked()
{
    QFile helpFile(":/help/Help.txt");
    if(helpFile.open(QIODevice::ReadOnly))
    {
        QByteArray ba = helpFile.readAll();
        QString text(ba);
        ui->plainTextEdit->setPlainText(text);
        helpFile.close();
    }
}

