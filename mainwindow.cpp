#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    escena->setSceneRect(0,0,759,529);
    ui->graphicsView->setScene(escena);
    pacman = new Bolita(50,50,15);
    escena->addItem(pacman);

    QBrush brochaF(Qt::black);
    ui->graphicsView->setBackgroundBrush(brochaF);


    string linea, linea2,linea3;
    ifstream archivoLectura, archivoLectura2,archivoLectura3;
    archivoLectura.open("coordenadas.txt");
    if(archivoLectura.is_open()){
        while(getline(archivoLectura, linea)){
            int x, y, ancho, alto;

            istringstream ss(linea);
            string token;
            int index = 0;
            while (getline(ss, token, ',')) {
                if (index == 0) {
                    x = stoi(token); // Convierte la cadena a entero
                } else if (index == 1) {
                    y = stoi(token);
                } else if (index == 2) {
                    ancho = stoi(token);
                } else if (index == 3) {
                    alto = stoi(token);
                }
                index++;
            }
            muros.push_back(new Muro(x,y,ancho,alto));
            escena->addItem(muros.back());
        }
    }

    archivoLectura2.open("coordenadas2.txt");
    if(archivoLectura2.is_open()){
        while(getline(archivoLectura2,linea2)){
            int x, y, r;

            istringstream ss(linea2);
            string token;
            int index = 0;
            while (getline(ss, token, ',')) {
                if (index == 0) {
                    x = stoi(token); // Convierte la cadena a entero
                } else if (index == 1) {
                    y = stoi(token);
                } else if (index == 2) {
                    r = stoi(token);
                }
                index++;
            }
            puntos.push_back(new punto(x,y,r));
            escena->addItem(puntos.back());
        }
    }

    archivoLectura3.open("coordenadas3.txt");
    if(archivoLectura3.is_open()){
        while(getline(archivoLectura3, linea3)){
            int x, y, ancho, alto;

            istringstream ss(linea3);
            string token;
            int index = 0;
            while (getline(ss, token, ',')) {
                if (index == 0) {
                    x = stoi(token); // Convierte la cadena a entero
                } else if (index == 1) {
                    y = stoi(token);
                } else if (index == 2) {
                    ancho = stoi(token);
                } else if (index == 3) {
                    alto = stoi(token);
                }
                index++;
            }
            fantasmas.push_back(new Fantasma(x,y,ancho,alto));
            escena->addItem(fantasmas.back());
        }
    }

    Timer = new QTimer(this);
    Timer->start(100);
    connect(Timer, SIGNAL(timeout()), this, SLOT(actualizarFantasmas()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W){
        if(!evaluarColision()){
            colisionPuntos();
            pacman->moverArriba();
        }
        else{
            pacman->moverAbajo();
        }
    }
    else if(ev->key()==Qt::Key_S){
        if(!evaluarColision()){
            colisionPuntos();
            pacman->moverAbajo();
        }
        else{
            pacman->moverArriba();
        }
    }
    else if(ev->key()==Qt::Key_D){
        if(!evaluarColision()){
            colisionPuntos();
            pacman->moverDerecha();
        }
        else{
            pacman->moverIzquierda();
        }
    }
    else if(ev->key()==Qt::Key_A){
        if(!evaluarColision()){
            colisionPuntos();
            pacman->moverIzquierda();
        }
        else{
            pacman->moverDerecha();
        }
    }
}

bool MainWindow::evaluarColision()
{
    for(QList<Muro *>::iterator it=muros.begin(); it!=muros.end(); it++){
        if(pacman->collidesWithItem(*it)){
            return true;
        }
    }
    return false;
}


void MainWindow::colisionPuntos()
{
    int i = 0;
    for(QList<punto *>::iterator it=puntos.begin(); it!=puntos.end(); it++){
        if(pacman->collidesWithItem(*it)){
            pacman->setPuntaje(pacman->getPuntaje()+1);
            ui->lblPuntaje->setText("Puntaje: "+QVariant(pacman->getPuntaje()).toString());
            QGraphicsItem* item = puntos.takeAt(i);
            escena->removeItem(item);
            puntos.removeOne(item);
            delete item;
        }
        i++;
    }

}

void MainWindow::actualizarFantasmas()
{
    foreach (Fantasma* fantasma, fantasmas) {
        fantasma->actualizarPosicion();
    }
}

