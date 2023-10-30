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
    pacman = new Bolita(100,100,20);
    escena->addItem(pacman);

    string linea;
    ifstream archivoLectura;
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

    //muros.push_back(new Muro(0,0,759,20));
    //escena->addItem(muros.back());
    /*
    Hacerlo leyendo un txt con toda la info
    muros.push_back(new Muro(x,y,ancho,alto));
    escena->addItem(muros.back());
    */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_W)
        pacman->moverArriba();
    else if(ev->key()==Qt::Key_S)
        pacman->moverAbajo();
    else if(ev->key()==Qt::Key_D)
        pacman->moverDerecha();
    else if(ev->key()==Qt::Key_A)
        pacman->moverIzquierda();
}


