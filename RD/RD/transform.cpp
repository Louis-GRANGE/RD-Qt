#include "transform.h"

Transform::Transform()
{
    position = QVector3D(0,0,0);
    rotation = QQuaternion(0,45,0,1);
    scale = QVector3D(1, 1, 1);
}

void Transform::Move(QVector3D direction)
{
    position += direction;
}

void Transform::Rotation(QVector3D direction)
{
    //rotation = direction;
}
