#include "punto.h"
#include <QPainter>

punto::punto()
{

}

punto::punto(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    setPos(posx,posy);
}

QRectF punto::boundingRect() const
{
    return QRect(-radio,-radio,2*radio,2*radio);
}

void punto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());
}
