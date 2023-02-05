#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
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


void MainWindow::on_buttonChoice_clicked()
{
    QString str;
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty())
        return;
    QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        str = text;
        ui->buttonChoice;
        file.close();
    }

    int pos = 0;
    while(1)
    {
        if((pos =str.indexOf("\"USD\",\"rate\"",pos))!=-1 && ui->lineEditUSD->displayText().isEmpty())
        {
            ui->lineEditUSD->setText(str.mid(pos+13,5));
        }
        if((pos = str.indexOf("\"EUR\",\"rate\"",pos))!=-1 && ui->lineEditEuro->displayText().isEmpty())
        {
            ui->lineEditEuro->setText(str.mid(pos+13,5));
        }
        if((pos = str.indexOf("near\":{\"temp", pos))!=-1 && ui->lineEditWeatherMorning->displayText().isEmpty())
        {
            ui->lineEditWeatherMorning->setText(str.mid(pos+15, 3));
        }
        if((pos = str.indexOf("near2\":{\"te", pos))!=-1 && ui->lineEditWeatherDay->displayText().isEmpty() )
        {
            ui->lineEditWeatherDay->setText(str.mid(pos+16, 3));
        }
        if((pos = str.indexOf("near3\":{\"temp", pos))!=-1 && ui->lineEditWeatherEvening->displayText().isEmpty() )
        {
            ui->lineEditWeatherEvening->setText(str.mid(pos+16, 3));
            break;
        }
        if(ui->lineEditWeatherEvening->displayText().isEmpty())
            break;
    }
}
