#ifndef ROOM_H
#define ROOM_H

#include <QVector2D>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>

class Room
{
public:
    Room(QVector2D size, QVector2D position, bool canEnter);
    void DrawRoom(QGraphicsScene *scene);

    QVector2D Size;
    QVector2D Position;
    bool CanEnter;
};

#endif // ROOM_H
