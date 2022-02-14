#include "transform.h"

Transform::Transform()
{
    //rotation = QQuaternion(0,45,0,1);
}

Transform::Transform(QVector3D pos, QVector3D rot)
{
    position = pos;
    rotation = rot;
}

void Transform::Move(QVector3D direction)
{
    position += direction;
}

void Transform::Rotation(QVector3D direction)
{
    rotation = QVector3D(direction.x(), direction.y(), direction.z());
}

QVector3D Transform::forward()
{
    float x = sin(qDegreesToRadians(rotation.y()));
    float z = -cos(qDegreesToRadians(rotation.y()));

    return QVector3D{x,0,z};
}

QVector3D Transform::right()
{
    float x = cos(qDegreesToRadians(rotation.y()));
    float z = sin(qDegreesToRadians(rotation.y()));

    return QVector3D{x,0,z};
}

QVector3D Transform::up()
{
    return QVector3D{0,1,0};
}
