#include "transform.h"

Transform::Transform()
{
    position = QVector3D();
    rotation = QVector3D();
}

void Transform::Move(QVector3D direction)
{
    position += direction;
}

void Transform::Rotation(QVector3D direction)
{
    //rotation = direction;
}
