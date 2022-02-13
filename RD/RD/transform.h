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
    QVector3D position = {0, 0, 0};
    QVector3D rotation;// = {0, 0, 0, 0};
    QVector3D scale = {1, 1, 1};
};

#endif // TRANSFORM_H
