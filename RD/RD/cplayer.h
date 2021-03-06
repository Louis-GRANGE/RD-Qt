#ifndef CPLAYER_H
#define CPLAYER_H
#include "cobject.h"
#include "cinputcontroller.h"
#include "camera.h"

class CPlayer : public CObject
{
public:
    CPlayer();
    CPlayer(Camera* cam);
    CInputController inputController;
    Camera* PlayerCamera;

    void Move(QVector3D newMovement);

    void Update();
};

#endif // CPLAYER_H
