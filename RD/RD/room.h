#ifndef ROOM_H
#define ROOM_H

#include <QVector2D>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

class Room
{
public:
    Room(QVector2D size, QVector2D position);
    void DrawRoom(QGraphicsScene *scene);
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
