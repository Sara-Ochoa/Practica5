#ifndef MURO_H
#define MURO_H
#include <QGraphicsItem>

class Muro: public QGraphicsItem
{
    int posx;
    int posy;
    int alto;
    int ancho;
public:
    Muro();
    Muro(int x, int y, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // MURO_H
