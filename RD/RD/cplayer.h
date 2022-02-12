#ifndef CPLAYER_H
#define CPLAYER_H
#include "cobject.h"
#include "cinputcontroller.h"

class CPlayer : CObject
{
public:
    CPlayer();
    CInputController inputController;
};

#endif // CPLAYER_H
