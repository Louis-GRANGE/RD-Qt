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
#include "scenemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    //Reload random seed with current time
    srand((int) time(0));

/*
    QVector3D * v3 = new QVector3D(1,2,3);
    QLabel *label = new QLabel(&w);
    label->setText("first line\nsecond line");
*/
    QGraphicsView * view = new QGraphicsView();
    view->setMinimumSize(500, 500);
    view->setFixedSize(500+2*view->frameWidth(), 500+2*view->frameWidth());
    Labyrinthe * laby = new Labyrinthe(view, QVector2D(10, 10));

    Camera* Cam = new Camera();
    CPlayer * player = new CPlayer(Cam);
    Singleton<GLDisplayWidget>::getInstance().MainPlayer = player;
    Singleton<SceneManager>::getInstance().SetReference(player, laby);

    //DISPLAY Window
    w.show();
    return a.exec();
}
