#include "cplayer.h"

CPlayer::CPlayer()
{
    inputController = CInputController();

    //Active Update function
    IsTickEnable = true;
    //transform.rotation = {0, 45, 0, 0};

    /*std::vector<QVector3D> vertices = {
        QVector3D(-0.5,0.8,0),
        QVector3D(0,1.6,0),
        QVector3D(0.5,0.8,0)
    } ;
    std::vector<int> triangles = {0, 1, 2};

    std::vector<QVector3D> colors = {QVector3D(0.5,0.8,0)};

    drawObject.data = {vertices, triangles, colors};*/

    drawObject.data = getDataMesh("D:/Documents/GitHub/RD-Qt/RD/Resources/Penico.obj");
}

void CPlayer::ActualizeTransform(QVector3D newMovement)
{
    transform.Move(newMovement);
    transform.Rotation(newMovement*10);
}

void CPlayer::Update()
{
    ActualizeTransform(inputController.KeyControl());
    inputController.SpawnNewPlayer();
}
