#include "cinputcontroller.h"
#include <QVector3D>
#include "cplayer.h"

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

//MAYBE TO DELETE
void CInputController::SpawnNewPlayer()
{
    if(GetKeyState('N') < 0)
        new CPlayer();
}

void CInputController::ToggleView(CPlayer* ref)
{
    if(GetKeyState('C') < 0)
        ref->Camera->transform.position = ref->transform.position;
}
