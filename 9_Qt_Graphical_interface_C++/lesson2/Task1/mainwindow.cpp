#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parsetext.h"

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


void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();
    qint32 pos = 0;
    while(1)
    {
        int fnd = txt.indexOf("#@",pos);
        if(fnd==-1) return;
        pos = fnd+1;
        qint32 en = txt.indexOf("@", pos+1);
        qint32 space = txt.indexOf(" ", pos);
        if((en<space || space==-1) && en!=-1)
        {
            ParseText parseText(txt.mid(fnd+2,en-fnd-2));
            QString num = parseText.parse();
            if(num=="NotInTheDatabase")
                continue;
            txt.insert(en+1, num);
            txt.remove(fnd, en);
            ui->plainTextEdit->setPlainText(txt);
        }
    }
}

