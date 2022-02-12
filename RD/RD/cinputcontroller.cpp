#include "cinputcontroller.h"
#include <QVector3D>

CInputController::CInputController()
{

}

QVector3D CInputController::KeyControl()
{
    newMovement = new QVector3D();

    if(GetKeyState('Z') < 0)
    {
        *newMovement += QVector3D(0,0.3,0);
    }
    else if(GetKeyState('S') < 0)
    {
        *newMovement += QVector3D(0,-0.3,0);
    }
    if(GetKeyState('D') < 0)
    {
        *newMovement += QVector3D(0.3,0,0);
    }
    else if(GetKeyState('Q') < 0)
    {
        *newMovement += QVector3D(-0.3,0,0);
    }

    return *newMovement;
}
