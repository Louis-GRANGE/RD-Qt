#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QVector2D>
#include <QList>
#include <QGraphicsView>

#include "room.h"

class Labyrinthe
{
public:
    Labyrinthe(QGraphicsView * view, QVector2D size);
    QVector2D Size;
    std::vector<Room*> vRooms;

    Room* GetUpRoom(Room* current);
    Room* GetDownRoom(Room* current);
    Room* GetRightRoom(Room* current);
    Room* GetLeftRoom(Room* current);

    Room* GetRoomAt(QVector2D pos);
    bool HaveNextToRoomWithAllWalls(Room* current);
    Room* GetRandomNextToRoomNoVisited(Room* current);
    Room* GetRandomNextToRoom(Room* current);
    void RemoveBetweenWalls(Room* current, Room* dest);
    void VisitRoom(Room* Destination, std::vector<Room*>* tmpRoom);

    void Visit(QVector2D pos);
    int IsInBounds(QVector2D pos);
};

#endif // LABYRINTHE_H
