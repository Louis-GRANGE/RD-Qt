#ifndef COBJECT_H
#define COBJECT_H

#include "transform.h"
#include "collision.h"
#include "cdrawobject.h"

class CObject
{
public:
    CObject();
    bool IsTickEnable = false;
    Transform transform;
    Collision collision;
    cDrawObject drawObject;
    modele getDataMesh(QString path);

    virtual void Update(){};

    virtual void Start(){};

    virtual void Move(QVector3D newMovement){};

private:
    bool IsInit = false;
};

#endif // COBJECT_H
