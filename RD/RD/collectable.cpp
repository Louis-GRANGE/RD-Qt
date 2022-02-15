#include "collectable.h"

Collectable::Collectable()
{
    //transform.scale = QVector3D(0.1f,0.1f,0.1f);
    drawObject.data = getDataMesh("Penico.obj");
    drawObject.data.colors = {{1,0,0}};

    collision = Collision();
    collision.myCollisionType = CollisionType::Trigger;
    collision.myColliderType = ColliderType::Box;
    collision.min = QVector3D(-3, 0, -1);
    collision.max = QVector3D(3, 0, 5);
}
