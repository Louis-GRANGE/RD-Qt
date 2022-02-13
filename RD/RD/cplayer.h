#ifndef CPLAYER_H
#define CPLAYER_H
#include "cobject.h"
#include "cinputcontroller.h"

class CPlayer : public CObject
{
public:
    CPlayer();
    CInputController inputController;
    void ActualizeTransform(QVector3D newMovement);

    void Update();
};

#endif // CPLAYER_H
