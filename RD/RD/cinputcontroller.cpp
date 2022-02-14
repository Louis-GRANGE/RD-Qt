#include "cinputcontroller.h"
#include <QVector3D>
#include "cplayer.h"

CInputController::CInputController()
{

}

QVector3D CInputController::KeyControl(CPlayer* ref)
{
    newMovement = new QVector3D();

    if(GetKeyState('Z') < 0)
    {
        *newMovement += ref->transform.forward();
    }
    else if(GetKeyState('S') < 0)
    {
        *newMovement -= ref->transform.forward();
    }
    if(GetKeyState('D') < 0)
    {
        *newMovement += ref->transform.right();
    }
    else if(GetKeyState('Q') < 0)
    {
        *newMovement -= ref->transform.right();
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
        ref->PlayerCamera->ToggleView();
}
