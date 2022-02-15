#include "cplayer.h"
#include "collision.h"

CPlayer::CPlayer()
{
    inputController = CInputController();

    //Active Update function
    IsTickEnable = true;

    drawObject.data = getDataMesh("D:/Documents/Document/Ynov/RD/RD-Qt/RD/Resources/Cube.obj");
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

    qDebug() << QDir::currentPath();
}

void CPlayer::Update()
{
    Move(inputController.KeyControl(this));
    inputController.SpawnNewPlayer();
    inputController.ToggleView(this);
}
