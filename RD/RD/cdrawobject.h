#ifndef CDRAWOBJECT_H
#define CDRAWOBJECT_H
#include <QVector3D>
#include <QVector>

struct modele
{
    std::vector<QVector3D> vertices;
    std::vector<int> triangles;
    std::vector<QVector3D> colors;
};

class cDrawObject
{
public:
    cDrawObject();
    cDrawObject(modele _data);
    modele data;
};

#endif // CDRAWOBJECT_H
