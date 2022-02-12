#ifndef CINPUTCONTROLLER_H
#define CINPUTCONTROLLER_H
#include <QKeyEvent>
#include <Windows.h>
#include "iostream"

using namespace std;

class CInputController
{
public:
    CInputController();
    QVector3D *newMovement;
    QVector3D KeyControl();
};

#endif // CINPUTCONTROLLER_H
