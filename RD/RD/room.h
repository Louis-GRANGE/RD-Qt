#ifndef ROOM_H
#define ROOM_H

#include "cobject.h"

#include <QVector2D>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

class Room : CObject
{
public:
    Room(QVector2D size, QVector2D position);
    void DrawRoom(QGraphicsScene *scene);
    void InitColliders();

    // 3D Edit mesh of CObject
    void EditMeshRoom3D(QGraphicsScene *scene);
    void EditMeshWallRoom3D(QVector2D p1,QVector2D p2, QGraphicsScene *scene, Qt::GlobalColor color);

    void DrawWall(QVector2D p1,QVector2D p2, QGraphicsScene *scene, Qt::GlobalColor color);
    int NumberOfWalls();

    bool HaveWallUP = true;
    bool HaveWallDOWN = true;
    bool HaveWallLEFT = true;
    bool HaveWallRIGHT = true;

    bool IsVisited = false;

    QVector2D Size;
    QVector2D WorldPosition;
    QVector2D RelativePosition;
};

#endif // ROOM_H
