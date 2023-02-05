#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QStandardItemModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButAddYP_clicked();
    void on_pushButDelYP_clicked();
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
};
#endif // MAINWINDOW_H
