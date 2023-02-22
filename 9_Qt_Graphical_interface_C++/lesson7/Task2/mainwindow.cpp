#include "mainwindow.h"
#include <QMessageBox>
#include <QLocale>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scence = new QGraphicsScene(this);
    setScene(scence);
    bscheme = new QList<BlockScheme*>;
}

MainWindow::~MainWindow()
{
    delete bscheme;
}

void MainWindow::reDraw()
{
    scence->update();
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        bscheme->append(new BlockScheme(this, figure));
        scence->addItem(bscheme->at(figure));

        connect(bscheme->at(figure), SIGNAL(reDraw()), this, SLOT(reDraw()));
        figure++;
    }
    else if(event->button() == Qt::RightButton)
    {
        QGraphicsItem* temp;
        for(int i = 0; i < figure; i++)
        {
            temp = bscheme->at(i);
            if(temp->scenePos().rx() > QCursor::pos().rx())
            {
                bscheme->remove(i);
                figure--;
            }
        }
    }
}

