#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QVector3D>

class Transform
{
public:
    Transform();
    void Move(QVector3D direction);
    void Rotation(QVector3D direction);
    QVector3D position;
    QVector3D rotation;
};

#endif // TRANSFORM_H
