#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButAdd_clicked()
{

    ui->plainText2->moveCursor(QTextCursor::End);
    ui->plainText2->insertPlainText(ui->plainText1->toPlainText());
    ui->plainText2->moveCursor(QTextCursor::End);
}


void MainWindow::on_pushButReplacement_clicked()
{
    QString str = ui->plainText1->toPlainText();
    ui->plainText2->setPlainText(str);
}


void MainWindow::on_pushButAddHTML_clicked()
{
    ui->plainText2->moveCursor(QTextCursor::End);
    ui->plainText2->appendHtml("<font color='red'>Hello</font>");
    ui->plainText2->moveCursor(QTextCursor::End);
}

