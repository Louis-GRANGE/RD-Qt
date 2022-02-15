#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "cplayer.h"
#include "labyrinthe.h"



class SceneManager : public Singleton<SceneManager>
{
public:
    SceneManager();
    void SetReference(CPlayer* _PlayerRef, Labyrinthe* _LabyrintheRef);

    CPlayer* PlayerRef;
    Labyrinthe* LabyrintheRef;
};

#endif // SCENEMANAGER_H
