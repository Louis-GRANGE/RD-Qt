#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <QVector3D>
#include "qmath.h"

class Transform
{
public:
    Transform();
    void Move(QVector3D direction);
    void Rotation(QVector3D direction);
    QVector3D position = {0, 0, 0};
    QVector3D rotation = {0, 0, 0};
    QVector3D scale = {1, 1, 1};

    QVector3D forward();
    QVector3D right();
    QVector3D up();
};

#endif // TRANSFORM_H
