#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H

#include <QGLWidget> // Module QtOpengL (classes QGLxxx in Qt4),
                     // with widget and rendering classes descending from QGLWidget,
                     // deprecated for module QtGui (classes QOpenGLxxx )
                     // and module widgets (QWidget, QGraphicsView).
#include <QtWidgets>
#include <QList>
#include <QTimer>
#include "cobject.h"
#include "cplayer.h"

class GLDisplayWidget : public QGLWidget
{
    friend class QMainWindow;
    friend class MainWindow;
public:
    explicit GLDisplayWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL(); // Display the scene Gl
    void resizeGL(int width, int height);
    CPlayer* player;
    QList<CObject*> assets;
    void draw(QVector3D worldpos, modele data);
    void drawTriangle(QVector3D worldpos, QVector3D pos1, QVector3D pos2, QVector3D pos3, QVector3D color);

protected:
    // Mouse Management
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:

    QTimer _timer; // To update the scene
    float _X, _Y ,_Z; // Translation

    QPoint _lastPosMouse; // To keep the last position of the mouse
};

#endif // GLDISPLAYWIDGET_H
