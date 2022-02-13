#include "transform.h"

Transform::Transform()
{
    //rotation = QQuaternion(0,45,0,1);
}

void Transform::Move(QVector3D direction)
{
    position += direction;
}

void Transform::Rotation(QVector3D direction)
{
    rotation = QVector3D(direction.x(), direction.y(), direction.z());
}
