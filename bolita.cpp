#include "bolita.h"
#include <QPainter>
#include <QPixmap>

Bolita::Bolita()
{
    posx=0;
    posy=0;
    radio=0;
    velocidad=3;
}

Bolita::Bolita(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=3;

    setPos(posx, posy);
}

void Bolita::moverArriba()
{
    posy -= velocidad;
    setPos(posx, posy);
}

void Bolita::moverAbajo()
{
    posy += velocidad;
    setPos(posx, posy);
}

void Bolita::moverDerecha()
{
    posx += velocidad;
    setPos(posx, posy);
}

void Bolita::moverIzquierda()
{
    posx -= velocidad;
    setPos(posx, posy);
}

QRectF Bolita::boundingRect() const
{
    return QRect(-radio, -radio, 2*radio,2*radio);
}

void Bolita::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /*
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
    */
    QPixmap pixmap(":/imagen/pac-man.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
