#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    escena->setSceneRect(0,0,759,529);
    ui->graphicsView->setScene(escena);
    pacman = new Bolita(50,50,20);
    escena->addItem(pacman);

    QBrush brochaF(Qt::black);
    ui->graphicsView->setBackgroundBrush(brochaF);


    string linea, linea2;
    ifstream archivoLectura, archivoLectura2;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W){
        if(!evaluarColision()){
            pacman->moverArriba();
        }
        else{
            pacman->moverAbajo();
        }
    }
    else if(ev->key()==Qt::Key_S){
        if(!evaluarColision()){
            pacman->moverAbajo();
        }
        else{
            pacman->moverArriba();
        }
    }
    else if(ev->key()==Qt::Key_D){
        if(!evaluarColision()){
            pacman->moverDerecha();
        }
        else{
            pacman->moverIzquierda();
        }
    }
    else if(ev->key()==Qt::Key_A){
        if(!evaluarColision()){
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

bool MainWindow::colisionPuntos()
{
    for(QList<punto *>::iterator it=puntos.begin(); it!=puntos.end(); it++){
        if(pacman->collidesWithItem(*it)){
            return true;
        }
    }
    return false;
}



