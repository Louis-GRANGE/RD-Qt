#include "cplayer.h"
#include <QWidget>

CPlayer::CPlayer()
{
    inputController = CInputController();

    /*std::vector<QVector3D> vertices = {
        QVector3D(-0.5,0.8,0),
        QVector3D(0,1.6,0),
        QVector3D(0.5,0.8,0)
    } ;
    std::vector<int> triangles = {0, 1, 2};

    std::vector<QVector3D> colors = {QVector3D(0.5,0.8,0)};

    drawObject.data = {vertices, triangles, colors};*/

    drawObject.data = getDataMesh("D:/GitHub/RD-Qt/RD/Resources/Penico.obj");
}

void CPlayer::ActualizeTransform(QVector3D newMovement)
{
    transform.Move(newMovement);
    transform.Rotation(newMovement);
}
