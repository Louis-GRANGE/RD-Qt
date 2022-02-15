#ifndef LINECOLLISION_H
#define LINECOLLISION_H

#include "collision.h"
#include <QVector3D>

class linecollision : public Collision
{
public:
    QVector3D min, max;
    linecollision(QVector3D _min, QVector3D _max){min = _min; max = _max;}
};
#endif // LINECOLLISION_H
