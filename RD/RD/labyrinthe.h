#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <QVector2D>
#include <QList>
#include <QGraphicsView>

#include <iostream>

#include "room.h"
enum direction
{
    NORTH,
    SOUTH,
    WEST,
    EAST,
    NONE,
};


class Labyrinthe
{
public:
    Labyrinthe(QGraphicsView * view, QVector2D size);
    QVector2D Size;
    std::vector<std::vector<Room*>> MazeRooms;
    std::vector<Room*> Maze;
    QGraphicsScene * scene;
    QGraphicsView * view;
    QVector2D RoomSizeInit = {25, 25};

    Room* GetRoomAt(QVector2D pos);
    bool HaveNextToRoomWithAllWalls(Room* current);

    Room* GetRandomNextToVisitedRoom(Room* current);
    std::vector<Room*> GetAllNextToRoomNoVisited(Room* current);
    void AddAllNextToUnVisitedRooms(Room* Current, std::vector<Room*> *UnVistedRooms);

    void RemoveBetweenWalls(Room* current, Room* dest);
    void VisitRoom(Room* Destination, std::vector<Room*> *tmpRoom);

    direction GetDirection(QVector2D pos1, QVector2D pos2);
    void RemoveByDir(QVector2D pos, direction dir);
    std::vector<Room *> GetAllNextToRoom(QVector2D pos);
    Room *GetRoomAtPos(QVector2D pos);

    template <class T>
    Room *GetRoomOnPosition(T value);

    //GET RANDOM
    int GetRandomInRange(int min, int max);

    //to delete
    int* nbLoop = new int(0);
};

#endif // LABYRINTHE_H
