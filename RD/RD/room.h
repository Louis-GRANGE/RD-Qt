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
    void DrawRoom2D(QGraphicsScene *scene);
    void InitColliders();

    void DrawWall(QVector2D p1,QVector2D p2, QGraphicsScene *scene, QVector3D color);
    int NumberOfWalls();

    bool HaveWallUP = true;
    bool HaveWallDOWN = true;
    bool HaveWallLEFT = true;
    bool HaveWallRIGHT = true;

    bool IsVisited = false;
    bool Is2DDraw = false;

    QVector3D WallsColor = {0.12, 0.48, 0.55};
    QVector3D GroundColor = {0.75, 0.86, 0.97};
    QVector2D Size;
    QVector2D WorldPosition;
    QVector2D RelativePosition;
};

#endif // ROOM_H
