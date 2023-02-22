#include "blockscheme.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

BlockScheme::BlockScheme(QObject *parent, int figure) : QObject(parent), QGraphicsItem()
{
    x = 0;
    y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    geometry = Geometry::RECTANGLE;
    if(figure%3 == 0)
    {
        geometry = Geometry::RECTANGLE;
    }
    else if(figure%3 == 1)
    {
        geometry = Geometry::ELLIPS;
    }
    else
    {
        geometry = Geometry::STAR;
    }
    setPos(QCursor::pos());
    moving = false;
}

QPoint BlockScheme::getCoord()
{
    return bpoint;
}

void BlockScheme::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(brush);
    if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
    if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
    if (geometry == Geometry::STAR) painter->drawRect(x, y, 200, 100);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF BlockScheme::boundingRect() const
{
    return QRectF(x, y, 200, 100);
}
void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        moving = true;
        bpoint = event->pos().toPoint();
    }
}

void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        moving = false;
        emit reDraw();
    }
}

void BlockScheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (moving)
    {
        QPoint p = event->pos().toPoint() - bpoint;
        x += p.x();
        y += p.y();
        bpoint = event->pos().toPoint();
        emit reDraw();
    }
}
