#include "fantasma.h"
#include <QPixmap>
#include <QPainter>

Fantasma::Fantasma()
{

}

Fantasma::Fantasma(int x, int y, int ancho, int alto)
{
    posx = x;
    posy = y;
    this->ancho = ancho;
    this->alto = alto;
    velocidad = 20;

    setPos(posx,posy);
}

QRectF Fantasma::boundingRect() const
{
    return QRect(0, 0, ancho,alto);
}

void Fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap(":/imagen/fantasma.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Fantasma::actualizarPosicion()
{
    setPos(x()+velocidad,y());

    if(x() <= 110 || x() >= 600){
        velocidad *= -1; // Cambia la dirección al llegar a un borde.
    }

}
