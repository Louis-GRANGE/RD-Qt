#ifndef CINPUTCONTROLLER_H
#define CINPUTCONTROLLER_H
#include <QKeyEvent>
#include <Windows.h>
#include "iostream"

//#include "cplayer.h"


class CPlayer;
using namespace std;

class CInputController
{
public:
    CInputController();
    QVector3D *newMovement;
    QVector3D KeyControl();

    //Spawn New Player
    void SpawnNewPlayer();

    //Change View
    void ToggleView(CPlayer* ref);
};

#endif // CINPUTCONTROLLER_H
