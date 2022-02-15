#ifndef BOXCOLLISION_H
#define BOXCOLLISION_H

#include <QVector3D>
#include "collision.h"

class boxcollision : public Collision
{
public:
    QVector3D min, max;
    boxcollision(QVector3D _min, QVector3D _max){min = _min; max = _max;}
};

#endif // BOXCOLLISION_H
