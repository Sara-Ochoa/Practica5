#include "muro.h"
#include <QPainter>

Muro::Muro()
{

}

Muro::Muro(int x, int y, int ancho, int alto)
{
    posx = x;
    posy = y;
    this->ancho = ancho;
    this->alto = alto;

    setPos(posx,posy);

}

QRectF Muro::boundingRect() const
{
    return QRect(0, 0, ancho,alto);
}

void Muro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}
