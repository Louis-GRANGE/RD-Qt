#include "mainwindow.h"

#include <QApplication>

#include <QLabel>
#include <QVector3D>

#include "cube.h"
#include "labyrinthe.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

/*    if (!QGLFormat::hasOpenGL())
            qFatal("This system has no OpenGL support");
    Cube cube;
    cube.resize(300, 300);
    cube.show();

    QVector3D * v3 = new QVector3D(1,2,3);
    QLabel *label = new QLabel(&w);
    label->setText("first line\nsecond line");
*/
    QGraphicsView * view = new QGraphicsView();
    Labyrinthe *laby = new Labyrinthe(view, QVector2D(20, 20));

    //DISPLAY Window
    w.show();
    return a.exec();
}
