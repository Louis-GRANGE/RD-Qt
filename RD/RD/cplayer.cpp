#include "cplayer.h"
#include "collision.h"
#include "scenemanager.h"

CPlayer::CPlayer()
{
    inputController = CInputController();

    //Active Update function
    IsTickEnable = true;

    drawObject.data = getDataMesh("Cube.obj");
}

CPlayer::CPlayer(Camera* cam)
{
    PlayerCamera = cam;
    inputController = CInputController();


    //Active Update function
    IsTickEnable = true;

    transform.scale = QVector3D(0.05f,0.05f,0.05f);
    transform.position = {5,-5,7};

    collision = Collision();
    collision.myCollisionType = CollisionType::Dynamic;
    collision.myColliderType = ColliderType::Box;
    collision.min = QVector3D(1, 0, - 1);
    collision.max = QVector3D(3, 0, + 1);

    drawObject.data = getDataMesh("Cube.obj");

}

void CPlayer::Move(QVector3D newMovement)
{
    transform.Move(newMovement);
    PlayerCamera->transform.position = transform.position + PlayerCamera->Offset.position;

    PlayerCamera->transform.rotation = PlayerCamera->IsTopView ? PlayerCamera->Offset.rotation : transform.rotation + PlayerCamera->Offset.rotation;

    //Draw wall on scene
    Singleton<SceneManager>::getInstance().LabyrintheRef->GetRoomOnPosition(transform.position)->DrawRoom2D(Singleton<SceneManager>::getInstance().LabyrintheRef->scene);
    Singleton<SceneManager>::getInstance().LabyrintheRef->UpdatePlayerPosIn2D(QVector2D(transform.position.x(), transform.position.z()));
}

void CPlayer::Update()
{
    Move(inputController.KeyControl(this));
    inputController.SpawnNewPlayer();
    inputController.ToggleView(this);
}
