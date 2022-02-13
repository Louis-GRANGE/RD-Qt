#include "transform.h"

Transform::Transform()
{

}

void Transform::Move(QVector3D direction)
{
    position += direction;
}

void Transform::Rotation(QVector3D direction)
{
    rotation = QQuaternion(direction.x(), direction.y(), direction.z(), 0);
}
