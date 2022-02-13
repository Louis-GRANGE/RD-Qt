#ifndef CDRAWOBJECT_H
#define CDRAWOBJECT_H
#include <QVector3D>
#include <QVector>

//TO Draw Object
#include "GLDisplayWidget.h"

class cDrawObject
{
public:
    cDrawObject();
    cDrawObject(modele _data);
    modele data;
};

#endif // CDRAWOBJECT_H
