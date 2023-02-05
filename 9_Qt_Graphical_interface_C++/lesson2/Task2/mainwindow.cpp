#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon("./C++Icon.png"),"C++"));
    model->appendRow(new QStandardItem(QIcon("./PythonIcon.png"),"Python"));
    model->appendRow(new QStandardItem(QIcon("./JavaIcon.png"),"Java"));
    model->appendRow(new QStandardItem(QIcon("./C#Icon.png"),"C#"));
    model->appendRow(new QStandardItem(QIcon("./PHPIcon.png"),"PHP"));
    model->appendRow(new QStandardItem(QIcon("./JavaScriptIcon.png"),"JavaScript"));
    int i=0;
    while(model->item(i)!=nullptr)
    {
        model->item(i)->setEditable(true);
        i++;
    }

    ui->listView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listView->setDefaultDropAction(Qt::MoveAction);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButAddYP_clicked()
{
   model->appendRow(new QStandardItem(QIcon("./PCIcon.png"),""));
   QMessageBox messageBox(this);
   messageBox.addButton(tr("Ok"),QMessageBox::AcceptRole);
   QMessageBox::information(this, "Info", "Введите название в новой строке списка");
}


void MainWindow::on_pushButDelYP_clicked()
{
    QModelIndexList numRow = ui->listView->selectionModel()->selectedRows();
    if(!numRow.empty())
    {
        model->removeRow(numRow[0].row());
    }
    else
    {
        model->appendRow(new QStandardItem("Все элементы уже удалены"));
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0)
    {
        ui->listView->setViewMode(QListView::ListMode);

    }
    else
    {
       ui->listView->setViewMode(QListView::IconMode);
    }
}


