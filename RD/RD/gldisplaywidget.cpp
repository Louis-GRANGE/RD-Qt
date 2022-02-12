#include "gldisplaywidget.h"
#include <GL/glu.h>

#include "QDebug"
#include "QDir"
#include <iostream>
#include <filesystem>
#include "fstream"

#include "cplayer.h"


GLDisplayWidget::GLDisplayWidget(QWidget *parent) : QGLWidget(parent), _X(0), _Y(0), _Z(-10)
{
    // Update the scene
    connect( &_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer.start(16); // Starts or restarts the timer with a timeout interval of 16 milliseconds.

    player = new CPlayer();
    assets.push_back(player);
}

void GLDisplayWidget::initializeGL()
{
    // background color
    glClearColor(0.07, 0.04, 0.02, 1);

    // Shader
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    fprintf(stderr, "initialisation du Gl\n");
}

void GLDisplayWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Center the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, _Z);

    // Rotation
    //glRotatef(0.f, 90.0f, 0.0, 0.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1, 0 ,0);
        glVertex3f(-0.5,0.8,0);
        glVertex3f(0,1.6,0);
        glVertex3f(0.5,0.8,0);

        glColor3f(0, 0 ,1);
        glVertex3f(0,0,0);
        glVertex3f(0.5,0.8,0);
        glVertex3f(1,0,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0, 1 ,0);
        glVertex3f(-1,0,0);
        glVertex3f(-0.5,0.8f,0);
        glVertex3f(0,0,0);
        glVertex3f(-1,0,0);
    glEnd();

    player->ActualizeTransform(player->inputController.KeyControl());

    foreach(CObject* object, assets)
    {       
        draw(object->transform.position, object->drawObject.data);
    }
}

void GLDisplayWidget::draw(QVector3D worldpos, modele data)
{
    for(int t = 0; t < data.triangles.size(); t += 3)
    {
        QVector3D pos1 = data.vertices[data.triangles[t] - 1];
        QVector3D pos2 = data.vertices[data.triangles[t + 1] - 1];
        QVector3D pos3 = data.vertices[data.triangles[t + 2] - 1];

        drawTriangle(worldpos, pos1 , pos2, pos3, data.colors[0]);
    }
}

void GLDisplayWidget::drawTriangle(QVector3D worldpos, QVector3D pos1, QVector3D pos2, QVector3D pos3, QVector3D color)
{
    glBegin(GL_TRIANGLES);
        glColor3f(color.x(), color.y(), color.z());
        glVertex3f(pos1.x() + worldpos.x(),pos1.y() + worldpos.y(),pos1.z() + worldpos.z());
        glVertex3f(pos2.x()+ worldpos.x(),pos2.y() + worldpos.y(),pos2.z() + worldpos.z());
        glVertex3f(pos3.x()+ worldpos.x(),pos3.y()+ worldpos.y(),pos3.z() + worldpos.z());
        glVertex3f(pos1.x() + worldpos.x(),pos1.y() + worldpos.y(),pos1.z() + worldpos.z());
    glEnd();
}

void GLDisplayWidget::resizeGL(int width, int height){

    glViewport(0, 0, width, height); //Viewport in the world window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 3000.0f);

    updateGL();
}

// - - - - - - - - - - - - Mouse Management  - - - - - - - - - - - - - - - -
// When you click, the position of your mouse is saved
void GLDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    if( event != NULL ) {
        _lastPosMouse = event->pos();
        // Do stuff
        updateGL();
    }
}

// Mouse movement management
void GLDisplayWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - _lastPosMouse.x();
    int dy = event->y() - _lastPosMouse.y();

    if( event != NULL )
    {
        // Do stuff
        updateGL();
    }
}

// Mouse Management for the zoom (for instance)
void GLDisplayWidget::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta();
    double stepZoom = 0.25;
    if (!numDegrees.isNull())
    {
      _Z = (numDegrees.x() > 0 || numDegrees.y() > 0) ? _Z + stepZoom : _Z - stepZoom;
    }
}
