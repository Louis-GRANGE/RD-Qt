#include "gldisplaywidget.h"
#include <GL/glu.h>

#include "QDebug"
#include "QDir"
#include <iostream>
#include <filesystem>
#include "fstream"
#include "cplayer.h"
#include "testcollision.h"
#include "collision.h"
#include "cinputcontroller.h"


GLDisplayWidget::GLDisplayWidget(QWidget *parent) : QGLWidget(parent)//, _X(0), _Y(0), _Z(-10), _RX(0), _RY(0), _RZ(0)
{
    // Update the scene
    connect( &_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    _timer.start(16); // Starts or restarts the timer with a timeout interval of 16 milliseconds.

    //Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera = new Camera();
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

    //START Function of Object
    foreach(CObject* object, Singleton<GLDisplayWidget>::getInstance().assets) //Never use JUSTE "assets" because it's a wrong access to the SINGLETON
    {
        object->Start();
    }

    // 2D collision tests
    testcollision mytest = testcollision();
    CInputController mytestcontroller = CInputController();
    //qDebug() << mytest.SquareMultiLineIntersect(QVector2D(-1,-1),QVector2D(1,1));
}

void GLDisplayWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Center the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Rotation

        //qDebug() << "CAM X POS   : " << Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position.x();
        glRotatef(Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.rotation.y(), 0, 1, 0);
        glRotatef(Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.rotation.x(), 1, 0, 0);
        glRotatef(Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.rotation.z(), 0, 0, 1);

    //Translation
        glTranslatef(Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position.x() * -1, Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position.y() * -1, Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position.z() * -1);

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

    //player->ActualizeTransform(player->inputController.KeyControl());
    foreach(CObject* object, Singleton<GLDisplayWidget>::getInstance().assets) //Never use JUSTE "assets" because it's a wrong access to the SINGLETON
    {
        bool collided = false;
        if(object->collision.myCollisionType == CollisionType::Dynamic)
        {
            QVector3D movementToVerify = Singleton<GLDisplayWidget>::getInstance().MainPlayer->inputController.KeyControl(Singleton<GLDisplayWidget>::getInstance().MainPlayer);
            //foreach(CObject* targetObject, Singleton<GLDisplayWidget>::getInstance().assets)
            for(int i = 0; i < Singleton<GLDisplayWidget>::getInstance().assets.size(); i++)
            {
                CObject* targetObject = Singleton<GLDisplayWidget>::getInstance().assets[i];
                if(targetObject != object && object->collision.checkCollision(movementToVerify,
                                             targetObject->collision,
                                             QVector2D(object->transform.position.x() + movementToVerify.x(), object->transform.position.z() + movementToVerify.z()),
                                             QVector2D(targetObject->transform.position.x(), targetObject->transform.position.z()))){
                    if(targetObject->collision.myCollisionType != CollisionType::Trigger)
                        collided = true;
                    else
                    {
                        Singleton<GLDisplayWidget>::getInstance().assets.erase(Singleton<GLDisplayWidget>::getInstance().assets.begin() + i);
                    }

                }
            }
            //qDebug() << movementToVerify;
        }

        DrawByObject(object);
        if(object->IsTickEnable && !collided)
            object->Update();
    }
}

void GLDisplayWidget::DrawByObject(CObject* object)
{
    draw(object->transform.position, object->transform.scale, object->transform.rotation ,object->drawObject.data);
}

void GLDisplayWidget::draw(QVector3D worldpos, QVector3D scale, QVector3D rotation, modele data)
{
    for(size_t t = 0; t < data.triangles.size(); t += 3)
    {
        QVector3D pos1 = data.vertices[data.triangles[t] - 1];
        QVector3D pos2 = data.vertices[data.triangles[t + 1] - 1];
        QVector3D pos3 = data.vertices[data.triangles[t + 2] - 1];

        if(data.colors.size() >= data.triangles.size()/3)
            drawTriangle(worldpos, scale, rotation, pos1, pos2, pos3, data.colors[t/3]);
        else
            drawTriangle(worldpos, scale, rotation, pos1, pos2, pos3, data.colors[0]);
    }
}

void GLDisplayWidget::drawTriangle(QVector3D worldpos, QVector3D scale, QVector3D rotation, QVector3D pos1, QVector3D pos2, QVector3D pos3, QVector3D color)
{
    //INIT Quaternion angle radiant by Euler Degree angle
    QQuaternion MyQuaternion = {1, QVector3D(qDegreesToRadians(rotation.x()), qDegreesToRadians(rotation.y()), qDegreesToRadians(rotation.z())).normalized()};

    //CHANGE point by rotation of the object
    pos1 = MyQuaternion.rotatedVector(pos1);
    pos2 = MyQuaternion.rotatedVector(pos2);
    pos3 = MyQuaternion.rotatedVector(pos3);

    //CHANGE Scale and WorldPosition
    pos1 = pos1 * scale + worldpos;
    pos2 = pos2 * scale + worldpos;
    pos3 = pos3 * scale + worldpos;

    glBegin(GL_TRIANGLES);
        glColor3f(color.x(), color.y(), color.z());
        glVertex3f((pos1.x()),(pos1.y()),(pos1.z()));
        glVertex3f((pos2.x()),(pos2.y()),(pos2.z()));
        glVertex3f((pos3.x()),(pos3.y()),(pos3.z()));
        glVertex3f((pos1.x()),(pos1.y()),(pos1.z()));
    glEnd();
}

void GLDisplayWidget::resizeGL(int width, int height)
{
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
        float sensitivity = 0.01f;
        dx *= sensitivity;
        dy *= sensitivity;

        //float yaw = Camera->rotation.x() + dy;
        float pitch = Singleton<GLDisplayWidget>::getInstance().MainPlayer->transform.rotation.y() + dx;

        //Camera->rotation.setX(yaw);
        Singleton<GLDisplayWidget>::getInstance().MainPlayer->transform.rotation.setY(pitch);

        updateGL();
    }
}

// Mouse Management for the zoom (for instance)
void GLDisplayWidget::wheelEvent(QWheelEvent *event) {
    QPoint numDegrees = event->angleDelta();
    double stepZoom = (numDegrees.x() > 0 || numDegrees.y() > 0) ? 0.25f : - 0.25f;
    if (!numDegrees.isNull())
    {
        Singleton<GLDisplayWidget>::getInstance().MainPlayer->transform.position = Singleton<GLDisplayWidget>::getInstance().MainPlayer->transform.position + Singleton<GLDisplayWidget>::getInstance().MainPlayer->transform.forward() * stepZoom * 100;
        //Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position = Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.position + Singleton<GLDisplayWidget>::getInstance().MainPlayer->PlayerCamera->transform.forward() * stepZoom * -100;
    }
}

void GLDisplayWidget::AddCObject(CObject* newobj)
{
    assets.push_back(newobj);
    newobj->Start();
}
