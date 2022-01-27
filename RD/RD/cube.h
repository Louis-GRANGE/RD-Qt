#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QtOpenGL>

#include <QtWidgets>
#include <QtOpenGL>

#include <QColorDialog>
#include <GL/glu.h>

class Cube : public QGLWidget
{
public:
    Cube(QWidget *parent = 0);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
private:
    void draw();
    int faceAtPosition(const QPoint &pos);
    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[6];
    QPoint lastPos;
};

#endif // GLWIDGET_H
