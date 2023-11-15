#ifndef BOLITA_H
#define BOLITA_H
#include <QGraphicsItem>

class Bolita: public QGraphicsItem
{
    int posx;
    int posy;
    int radio;
    int velocidad;
    int puntaje;
    int vida=10;

public:
    Bolita();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    Bolita(int x, int y, int r);

    void moverArriba();
    void moverAbajo();
    void moverDerecha();
    void moverIzquierda();
    int getPuntaje() const;
    void setPuntaje(int newPuntaje);
    int getVida() const;
    void setVida(int newVida);
};

#endif // BOLITA_H
