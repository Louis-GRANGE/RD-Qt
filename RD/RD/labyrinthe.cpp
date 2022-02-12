#include "labyrinthe.h"
#include <iostream>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

Labyrinthe::Labyrinthe(QGraphicsView * view, QVector2D size)
{
    Size = size;
    //lRoom = new QList<Room>();
    QVector2D RoomSizeInit = QVector2D(25, 25);
    QGraphicsScene * scene = new QGraphicsScene();

    Room* Current;
    Room* Destination;

    for(int x = 0; x <= Size.x(); x++)
    {
        for(int y = 0; y <= Size.y(); y++)
        {
            Room* tmp = new Room(QVector2D(RoomSizeInit.x(), RoomSizeInit.y()), QVector2D(x, y));
            //tmp.DrawRoom(scene);
            vRooms.push_back(tmp);
        }
    }

    Current = vRooms[Size.x()+1];//Size.x()*Size.y() / 2];
    std::vector<Room*> tmpRoom;
    /*foreach(Room* tmp, vRooms)
    {
        tmpRoom.push_back(tmp);
    }*/

    //Recursivity to visit all Rooms
    VisitRoom(Current, &tmpRoom);
    //Visit(Current->RelativePosition);
    foreach(Room* tmp, vRooms)
    {
        tmp->DrawRoom(scene);
    }
    view = new QGraphicsView(scene);
    view->show();
}


void Labyrinthe::VisitRoom(Room* Current, std::vector<Room*>* tmpRoom)
{

    Room* Destination;

    if(tmpRoom->size() >= ((Size.x()-1)*(Size.y()-1) - 50))
        return;

    if(HaveNextToRoomWithAllWalls(Current))
    {
        Destination = GetRandomNextToRoomNoVisited(Current);

        RemoveBetweenWalls(Current, Destination);
        std::cout << "PrevPos: " << Current->RelativePosition.x() << "," << Current->RelativePosition.y() << std::endl;

        tmpRoom->push_back(Destination);
        VisitRoom(Destination, tmpRoom);
    }
    else
    {
        Destination = GetRandomNextToRoom(Current);
        VisitRoom(Destination, tmpRoom);
        //return;
    }

}


// This is the recursive function we will code in the next project
void Labyrinthe::Visit(QVector2D pos)
{
     // Starting at the given index, recursively visits every direction in a
     // randomized order.
     // Set my current location to be an empty passage.
     GetRoomAt(pos)->IsVisited = true;
     // Create an local array containing the 4 directions and shuffle their order.
     int dirs[4];
     dirs[0] = NORTH;
     dirs[1] = EAST;
     dirs[2] = SOUTH;
     dirs[3] = WEST;
     for (int i=0; i<4; ++i)
     {
         int r = rand() & 3;
         int temp = dirs[r];
         dirs[r] = dirs[i];
         dirs[i] = temp;
     }
     // Loop through every direction and attempt to Visit that direction.
     for (int i=0; i<4; ++i)
     {
         // dx,dy are offsets from current location. Set them based
         // on the next direction I wish to try.
         int dx=0, dy=0;
         switch (dirs[i])
         {
             case NORTH: dy = -1; break;
             case SOUTH: dy = 1; break;
             case EAST: dx = 1; break;
             case WEST: dx = -1; break;
         }
         // Find the (x,y) coordinates of the grid cell 2 spots
         // away in the given direction.
         int x2 = pos.x() + (dx<<1);
         int y2 = pos.y() + (dy<<1);
         if (IsInBounds(QVector2D(x2,y2)))
         {
             if (!GetRoomAt(QVector2D(x2,y2))->IsVisited)
             {
                 // (x2,y2) has not been visited yet... knock down the
                 // wall between my current position and that position
                 RemoveBetweenWalls(GetRoomAt(pos), GetRoomAt(QVector2D(x2,y2)));
                 //GetRoomAt(QVector2D(x2-dx,y2-dy))->IsVisited = true;
                 GetRoomAt(QVector2D(x2,y2))->IsVisited = true;
                 // Recursively Visit (x2,y2)
                 Visit(QVector2D(x2,y2));
             }
         }
     }
}

int Labyrinthe::IsInBounds(QVector2D pos)
{
 // Returns "true" if x and y are both in-bounds.
 if (pos.x() < 0 || pos.x() >= Size.x()) return false;
 if (pos.y() < 0 || pos.y() >= Size.y()) return false;
 return true;
}

Room* Labyrinthe::GetRoomAt(QVector2D pos)
{
    if((pos.x() + pos.y() * Size.y()) < vRooms.size())
        return vRooms[pos.x() * (Size.x()+1) + pos.y()]; //INDEX OUT OF RANGE
    else
        return nullptr;
}

Room* Labyrinthe::GetUpRoom(Room* current)
{
    if(current->RelativePosition.y() <= 0)
        return nullptr;
    else
        return GetRoomAt(QVector2D(current->RelativePosition.x(), current->RelativePosition.y() - 1));
}
Room* Labyrinthe::GetDownRoom(Room* current)
{
    if(current->RelativePosition.y() >= Size.y())
        return nullptr;
    else
        return GetRoomAt(QVector2D(current->RelativePosition.x(), current->RelativePosition.y() + 1));
}
Room* Labyrinthe::GetRightRoom(Room* current)
{
    if(current->RelativePosition.x() >= Size.x())
        return nullptr;
    else
        return GetRoomAt(QVector2D(current->RelativePosition.x() + 1, current->RelativePosition.y()));
}
Room* Labyrinthe::GetLeftRoom(Room* current)
{
    if(current->RelativePosition.x() <= 0)
        return nullptr;
    else
        return GetRoomAt(QVector2D(current->RelativePosition.x() - 1, current->RelativePosition.y()));
}

bool Labyrinthe::HaveNextToRoomWithAllWalls(Room* current)
{
    if (GetUpRoom(current) != nullptr && GetUpRoom(current)->NumberOfWalls() == 4)
        return true;
    if (GetDownRoom(current) != nullptr && GetDownRoom(current)->NumberOfWalls() == 4)
        return true;
    if (GetRightRoom(current) != nullptr && GetRightRoom(current)->NumberOfWalls() == 4)
        return true;
    if (GetLeftRoom(current) != nullptr && GetLeftRoom(current)->NumberOfWalls() == 4)
        return true;

    return false;
}

Room* Labyrinthe::GetRandomNextToRoomNoVisited(Room* current)
{
    std::vector<Room*> lAllWallsRoom = std::vector<Room*>();
    if (GetUpRoom(current) != nullptr && GetUpRoom(current)->NumberOfWalls() >= 4) //4
        lAllWallsRoom.push_back(GetUpRoom(current));
    if (GetDownRoom(current) != nullptr && GetDownRoom(current)->NumberOfWalls() >= 4) //4
        lAllWallsRoom.push_back(GetDownRoom(current));
    if (GetRightRoom(current) != nullptr && GetRightRoom(current)->NumberOfWalls() >= 4) //4
        lAllWallsRoom.push_back(GetRightRoom(current));
    if (GetLeftRoom(current) != nullptr && GetLeftRoom(current)->NumberOfWalls() >= 4) //4
        lAllWallsRoom.push_back(GetLeftRoom(current));

    int index = rand()%(lAllWallsRoom.size());


    if(lAllWallsRoom[index] == nullptr)
        return nullptr;

    return lAllWallsRoom[index];
}

Room* Labyrinthe::GetRandomNextToRoom(Room* current)
{
    std::vector<Room*> lAllWallsRoom = std::vector<Room*>();
    if (GetUpRoom(current) != nullptr)
        lAllWallsRoom.push_back(GetUpRoom(current));
    if (GetDownRoom(current) != nullptr)
        lAllWallsRoom.push_back(GetDownRoom(current));
    if (GetRightRoom(current) != nullptr)
        lAllWallsRoom.push_back(GetRightRoom(current));
    if (GetLeftRoom(current) != nullptr)
        lAllWallsRoom.push_back(GetLeftRoom(current));

    int index = rand()%(lAllWallsRoom.size()-1);


    if(lAllWallsRoom[index] == nullptr)
        return nullptr;

    return lAllWallsRoom[index];
}


void Labyrinthe::RemoveBetweenWalls(Room* current, Room* dest)
{
    if (GetUpRoom(current)!= nullptr && GetUpRoom(current) == dest)
    {
        current->HaveWallUP = false;
        dest->HaveWallDOWN = false;
    }
    if (GetDownRoom(current)!= nullptr && GetDownRoom(current) == dest)
    {
        current->HaveWallDOWN = false;
        dest->HaveWallUP = false;
    }
    if (GetRightRoom(current)!= nullptr && GetRightRoom(current) == dest)
    {
        current->HaveWallRIGHT = false;
        dest->HaveWallLEFT = false;
    }
    if (GetLeftRoom(current)!= nullptr && GetLeftRoom(current) == dest)
    {
        current->HaveWallLEFT = false;
        dest->HaveWallRIGHT = false;
    }
}
