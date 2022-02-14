#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H
#pragma once

#include <QGLWidget> // Module QtOpengL (classes QGLxxx in Qt4),
                     // with widget and rendering classes descending from QGLWidget,
                     // deprecated for module QtGui (classes QOpenGLxxx )
                     // and module widgets (QWidget, QGraphicsView).
#include <QtWidgets>
#include <QList>
#include <QTimer>
//#include <QtMath>

//#include "cplayer.h"
#include "qmath.h"
#include "singleton.h"

//#include "cobject.h"
class CObject;
class CPlayer;

struct modele
{
    std::vector<QVector3D> vertices;
    std::vector<int> triangles;
    std::vector<QVector3D> colors;
};

class GLDisplayWidget : public QGLWidget, public Singleton<GLDisplayWidget>
{
    friend class QMainWindow;
    friend class MainWindow;
public:
    explicit GLDisplayWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL(); // Display the scene Gl
    void resizeGL(int width, int height);

    QList<CObject*> assets;
    CPlayer *MainPlayer; //Player Ref

    //DRAWING
    void draw(QVector3D worldpos, QVector3D scale, QVector3D rotation, modele data);
    void drawTriangle(QVector3D worldpos, QVector3D scale, QVector3D rotation, QVector3D pos1, QVector3D pos2, QVector3D pos3, QVector3D color);
    void DrawByObject(CObject* object);

protected:
    // Mouse Management
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:

    QTimer _timer; // To update the scene

    QPoint _lastPosMouse; // To keep the last position of the mouse


public: // COBJECT Access
    void AddCObject(CObject* newobj);
};

#endif // GLDISPLAYWIDGET_H
