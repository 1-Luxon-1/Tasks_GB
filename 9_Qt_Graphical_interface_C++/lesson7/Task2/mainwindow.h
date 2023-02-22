#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <blockscheme.h>
#include <QList>

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QGraphicsScene *scence;
    QGraphicsView *view;
    QList<BlockScheme*> *bscheme;
    QList<QGraphicsItem*> *grItem;
    int figure = 0;
private slots:
    void reDraw();
    void mousePressEvent(QMouseEvent *event);

};
#endif // MAINWINDOW_H
