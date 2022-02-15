#ifndef COMPLEXCOLLISION_H
#define COMPLEXCOLLISION_H

#include <QVector3D>
#include "collision.h"
#include "cdrawobject.h"

class complexcollision : public Collision
{
public:
    complexcollision();
    std::vector<QVector2D> vertices;
    std::vector<bool> isConnected;
};

#endif // COMPLEXCOLLISION_H
