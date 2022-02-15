#include "cplayer.h"
#include "collision.h"

CPlayer::CPlayer()
{
    inputController = CInputController();

    //Active Update function
    IsTickEnable = true;
}

CPlayer::CPlayer(Camera* cam)
{
    PlayerCamera = cam;
    inputController = CInputController();


    //Active Update function
    IsTickEnable = true;

    transform.scale = QVector3D(0.1f,0.1f,0.1f);
    /*collision = boxcollision(QVector3D(transform.position.x() - 1, 0,transform.position.z() - 1),
                             QVector3D(transform.position.x() + 1, 0,transform.position.z() + 1));*/
    collision = Collision();
    collision.myCollisionType = CollisionType::Dynamic;
    collision.myColliderType = ColliderType::Box;
    collision.min = QVector3D(transform.position.x() - 1, 0,transform.position.z() - 1);
    collision.max = QVector3D(transform.position.x() + 1, 0,transform.position.z() + 1);
    /*std::vector<QVector3D> vertices = {
        QVector3D(-0.5,0.8,0),
        QVector3D(0,1.6,0),
        QVector3D(0.5,0.8,0)
    } ;
    std::vector<int> triangles = {0, 1, 2};

    std::vector<QVector3D> colors = {QVector3D(0.5,0.8,0)};

    drawObject.data = {vertices, triangles, colors};*/

    drawObject.data = getDataMesh("D:/GitHub/RD-Qt/RD/Resources/Cube.obj");
}

void CPlayer::Move(QVector3D newMovement)
{
    transform.Move(newMovement);
    PlayerCamera->transform.position = transform.position + PlayerCamera->Offset.position;

    PlayerCamera->transform.rotation = PlayerCamera->IsTopView ? PlayerCamera->Offset.rotation : transform.rotation + PlayerCamera->Offset.rotation;
}

void CPlayer::Update()
{
    Move(inputController.KeyControl(this));
    inputController.SpawnNewPlayer();
    inputController.ToggleView(this);
}
