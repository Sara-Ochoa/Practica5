#ifndef FANTASMA_H
#define FANTASMA_H
#include <QGraphicsItem>

class Fantasma: public QGraphicsItem
{
    int posx;
    int posy;
    int alto;
    int ancho;
    int velocidad=10;
public:
    Fantasma();
    Fantasma(int x, int y, int ancho, int alto);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void actualizarPosicion();
};

#endif // FANTASMA_H
