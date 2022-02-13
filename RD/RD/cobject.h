#ifndef COBJECT_H
#define COBJECT_H

#include "transform.h"
#include "cdrawobject.h"


class CObject
{
public:
    CObject();
    bool IsTickEnable = false;
    Transform transform;
    cDrawObject drawObject;
    modele getDataMesh(QString path);

    virtual void Update(){};

    virtual void Start(){};

private:
    bool IsInit = false;
};

#endif // COBJECT_H
