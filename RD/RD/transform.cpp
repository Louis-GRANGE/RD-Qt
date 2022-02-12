#include "transform.h"

Transform::Transform()
{

}

void Transform::Move(QVector3D direction)
{
    *position += direction;
}

void Transform::Rotation(QVector3D targetRotation)
{
    *rotation = targetRotation;
}
