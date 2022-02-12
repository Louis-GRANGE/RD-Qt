#include "cinputcontroller.h"
#include <QVector3D>

CInputController::CInputController()
{

}

void CInputController::keyPressEvent(QKeyEvent *event)
{
    newMovement = new QVector3D();

    if(event->key() == Qt::Key_Z)
    {
        *newMovement += QVector3D(0,1,0);
    }
    else if(event->key() == Qt::Key_S)
    {
        *newMovement += QVector3D(0,-1,0);
    }
    if(event->key() == Qt::Key_D)
    {
        *newMovement += QVector3D(1,0,0);
    }
    else if(event->key() == Qt::Key_Q)
    {
        *newMovement += QVector3D(-1,0,0);
    }
}
