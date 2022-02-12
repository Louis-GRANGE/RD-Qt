#ifndef COBJECT_H
#define COBJECT_H
#include "transform.h"
#include "cdrawobject.h"

class CObject
{
public:
    CObject();
    Transform transform;
    cDrawObject drawObject;
    modele getDataMesh(QString path);
};

#endif // COBJECT_H
