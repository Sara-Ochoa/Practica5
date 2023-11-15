#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bolita.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "muro.h"
#include "punto.h"
#include "fantasma.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *ev);
    void actualizarFantasmas();
    void colisionFantasmas();

private:
    Ui::MainWindow *ui;
    Bolita *pacman;
    QGraphicsScene *escena;
    QList<Muro *> muros;
    bool evaluarColision();
    QList<punto *> puntos;
    void colisionPuntos();
    QList <Fantasma*> fantasmas;
    QTimer *Timer;
    QTimer *Timer1;

};
#endif // MAINWINDOW_H
