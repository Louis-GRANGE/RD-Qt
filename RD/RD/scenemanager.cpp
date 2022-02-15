#include "scenemanager.h"

SceneManager::SceneManager()
{

}

void SceneManager::SetReference(CPlayer *_PlayerRef, Labyrinthe *_LabyrintheRef)
{
    PlayerRef = _PlayerRef;
    LabyrintheRef = _LabyrintheRef;
}
