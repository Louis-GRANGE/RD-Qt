#include "collectable.h"

Collectable::Collectable()
{
    transform.scale = QVector3D(0.1f,0.1f,0.1f);
    drawObject.data = getDataMesh("Cube.obj");
    drawObject.data.colors = {{1,0,0}};
}
