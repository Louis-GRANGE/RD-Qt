#ifndef COLLISION_H
#define COLLISION_H

#include <QVector3D>
#include <QVector2D>
#include "testcollision.h"
#include "gldisplaywidget.h"
enum class CollisionType
  {
     Static,
     Dynamic,
     Trigger
  };

enum class ColliderType
{
    MultiLine,
    Box,
    Line
};

class Collision
{
public:
    Collision();
    CollisionType myCollisionType = CollisionType::Static;
    ColliderType myColliderType = ColliderType::MultiLine;

    // Used for BoxCollider types and LineCollider types
    QVector3D min, max;

    // Used for multiline
    std::vector<std::vector<QVector2D>> vertices;

    bool checkAllCollisions(QVector3D newMovement);
    bool checkCollision(QVector3D newMovement, Collision target, QVector2D pos, QVector2D targetpos);

    testcollision myTestCollision = testcollision();
};

#endif // COLLISION_H
