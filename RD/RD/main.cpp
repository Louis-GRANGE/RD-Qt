#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <QLabel>
#include <QVector3D>

#include "labyrinthe.h"
#include "cplayer.h"
#include "camera.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

/*
    QVector3D * v3 = new QVector3D(1,2,3);
    QLabel *label = new QLabel(&w);
    label->setText("first line\nsecond line");
*/
    QGraphicsView * view = new QGraphicsView();

    Labyrinthe * laby = new Labyrinthe(view, QVector2D(20, 20));

    Camera* Cam = new Camera();
    Singleton<GLDisplayWidget>::getInstance().Cam = Cam;

    CPlayer * player = new CPlayer(Cam);

    //DISPLAY Window
    w.show();
    return a.exec();
}
