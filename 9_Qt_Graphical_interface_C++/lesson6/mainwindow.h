#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

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
    void on_buttonOpen_clicked();

    void on_buttonSave_clicked();

    void on_buttunHelp_clicked();

    void on_buttonRead_clicked();

    void on_buttonLanguageEn_clicked();

    void on_buttonLanguageRus_clicked();

    void on_buttonTopic_clicked();

    void on_buttonPrint_clicked();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    char leng = 'R';
    char topic = 'W';
};
#endif // MAINWINDOW_H
