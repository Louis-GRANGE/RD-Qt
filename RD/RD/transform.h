#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QVector3D>
#include <QQuaternion>

class Transform
{
public:
    Transform();
    void Move(QVector3D direction);
    void Rotation(QVector3D direction);
    QVector3D position;
    QQuaternion rotation;
    QVector3D scale;
};

#endif // TRANSFORM_H
