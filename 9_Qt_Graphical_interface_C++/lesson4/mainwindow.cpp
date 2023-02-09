#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QKeyEvent>
#include <QKeySequence>
#include <Qt>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle("Главное окно");
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
        ui->plainTextEdit->setReadOnly(false);
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


void MainWindow::on_buttonRead_clicked()
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
        ui->plainTextEdit->setReadOnly(true);
        file.close();
    }
}



void MainWindow::on_buttonLanguageEn_clicked()
{
    if(leng=='R')
    {
        translator.load(":/lenguage/QtLanguage_en.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        leng = 'E';
    }
}


void MainWindow::on_buttonLanguageRus_clicked()
{
    if(leng == 'E')
    {
        translator.load(":/lenguage/QtLanguage_ru.qm");
        qApp->installTranslator(&translator);
        ui->retranslateUi(this);
        leng= 'R';
    }
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_O)
    {
        on_buttonOpen_clicked();
    }
    else if(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_S)
    {
        on_buttonSave_clicked();
    }
    else if(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Q)
    {
        qApp->quit();
    }
}


