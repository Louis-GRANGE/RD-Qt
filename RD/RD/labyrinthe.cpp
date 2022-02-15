#include "labyrinthe.h"
#include <ctime>



Labyrinthe::Labyrinthe(QGraphicsView * _view, QVector2D size)
{
    Size = size;
    view = _view;
    scene = new QGraphicsScene();
    //lRoom = new QList<Room>();

    Room* Current;


    //INIT ARRAY OF ARRAY
    for(int x = 0; x < Size.x(); x++)
    {
        std::vector<Room*> tmp = std::vector<Room*>(Size.y());
        MazeRooms.push_back(tmp);
        for(int y = 0; y < Size.y(); y++)
        {
            Room* tmp = new Room(QVector2D(RoomSizeInit.x(), RoomSizeInit.y()), QVector2D(x, y));
            MazeRooms[x][y] = tmp;
        }
    }
    //-------------------

    std::vector<Room*>* UnVisitedRooms = new std::vector<Room*>();
    Current = MazeRooms[0][0];
    AddAllNextToUnVisitedRooms(Current, UnVisitedRooms);
    Current->IsVisited = true;

    Room * tmp = UnVisitedRooms->at(GetRandomInRange(0, UnVisitedRooms->size()));
    for(size_t i = 0; i < UnVisitedRooms->size(); i++)
    {
        if(UnVisitedRooms->at(i) == tmp)
            UnVisitedRooms->erase(UnVisitedRooms->begin() + i);
    }
    RemoveBetweenWalls(Current, tmp);
    Current = tmp;

    //Recursivity to visit all Rooms
    VisitRoom(Current, UnVisitedRooms);


    // TO DRAW ALL ROOMS
    for(int x = 0; x < Size.x(); x++)
    {
        for(int y = 0; y < Size.y(); y++)
        {
            MazeRooms[x][y]->DrawRoom(scene);
            MazeRooms[x][y]->InitColliders();
        }
    }

    view->setScene(scene);
    view->show();
}


void Labyrinthe::VisitRoom(Room* Current, std::vector<Room*> *UnVisitedRooms)
{    
    //std::cout << "Pos: " << Current->RelativePosition.x() << " " << Current->RelativePosition.y() << std::endl;
    Current->IsVisited = true;
    Maze.push_back(Current);
    AddAllNextToUnVisitedRooms(Current, UnVisitedRooms);
    for(size_t i = 0; i < UnVisitedRooms->size(); i++)
    {
        if(UnVisitedRooms->at(i) == Current)
            UnVisitedRooms->erase(UnVisitedRooms->begin() + i);
    }
    if(!UnVisitedRooms->empty())
    {
        *nbLoop = *nbLoop + 1;
        //std::cout << "->" << *nbLoop << std::endl;

        Room* tmp = UnVisitedRooms->at(GetRandomInRange(0, UnVisitedRooms->size()));
        RemoveBetweenWalls(tmp, GetRandomNextToVisitedRoom(tmp));
        for(size_t i = 0; i < UnVisitedRooms->size(); i++)
        {
            if(UnVisitedRooms->at(i) == tmp)
                UnVisitedRooms->erase(UnVisitedRooms->begin() + i);
        }
        VisitRoom(tmp, UnVisitedRooms);
    }
}


void Labyrinthe::RemoveBetweenWalls(Room* current, Room* dest)
{
    RemoveByDir(current->RelativePosition, GetDirection(current->RelativePosition, dest->RelativePosition));
}


void Labyrinthe::AddAllNextToUnVisitedRooms(Room* Current, std::vector<Room*> *UnVisitedRooms)
{
    std::vector<Room*> tmpRooms = GetAllNextToRoomNoVisited(Current);
    for(size_t i = 0; i < tmpRooms.size(); i++)
    {
        UnVisitedRooms->push_back(tmpRooms[i]);
    }
}


direction Labyrinthe::GetDirection(QVector2D pos1, QVector2D pos2)
{
    if(pos1.x() > pos2.x())
        return WEST;
    if(pos1.x() < pos2.x())
        return EAST;
    if(pos1.y() > pos2.y())
        return NORTH;
    if(pos1.y() < pos2.y())
        return SOUTH;

    return NONE;
}
void Labyrinthe::RemoveByDir(QVector2D pos, direction dir)
{
    switch (dir)
    {
        case NORTH:
        {
            MazeRooms[pos.x()][pos.y()]->HaveWallUP = false;
            MazeRooms[pos.x()][pos.y() - 1]->HaveWallDOWN = false;
            break;
        }
        case SOUTH:
        {
            MazeRooms[pos.x()][pos.y()]->HaveWallDOWN = false;
            MazeRooms[pos.x()][pos.y() + 1]->HaveWallUP = false;
            break;
        }
        case WEST:
        {
            MazeRooms[pos.x()][pos.y()]->HaveWallLEFT = false;
            MazeRooms[pos.x() - 1][pos.y()]->HaveWallRIGHT = false;
            break;
        }
        case EAST:
        {
            MazeRooms[pos.x()][pos.y()]->HaveWallRIGHT = false;
            MazeRooms[pos.x() + 1][pos.y()]->HaveWallLEFT = false;
            break;
        }
        case NONE:
        {

        }
    }
}

Room* Labyrinthe::GetRandomNextToVisitedRoom(Room* current)
{
    std::vector<Room*> lAllRooms = std::vector<Room*>();
    std::vector<Room*> NextToRooms = GetAllNextToRoom(current->RelativePosition);

    for(size_t i = 0; i < NextToRooms.size(); i++)
    {
        if(NextToRooms[i]->IsVisited)
            lAllRooms.push_back(NextToRooms[i]);
    }

    int index = GetRandomInRange(0, lAllRooms.size());
    return lAllRooms[index];
}

Room* Labyrinthe::GetRoomAtPos(QVector2D pos)
{
    return MazeRooms[pos.x()][pos.y()];
}

int Labyrinthe::GetRandomInRange(int min, int max)
{
    return rand() % max + min;
}

std::vector<Room*> Labyrinthe::GetAllNextToRoom(QVector2D pos)
{
    std::vector<Room*> lAllRooms = std::vector<Room*>();

    if(pos.x() > 0)
        lAllRooms.push_back(MazeRooms[pos.x()-1][pos.y()]);
    if(pos.x() < Size.x()-1)
        lAllRooms.push_back(MazeRooms[pos.x()+1][pos.y()]);
    if(pos.y() > 0)
        lAllRooms.push_back(MazeRooms[pos.x()][pos.y()-1]);
    if(pos.y() < Size.y()-1)
        lAllRooms.push_back(MazeRooms[pos.x()][pos.y()+1]);

    return lAllRooms;
}
std::vector<Room*> Labyrinthe::GetAllNextToRoomNoVisited(Room* current)
{
    std::vector<Room*> lAllRooms = std::vector<Room*>();
    std::vector<Room*> NextToRooms = GetAllNextToRoom(current->RelativePosition);

    for(size_t i = 0; i < NextToRooms.size(); i++)
    {
        if(!NextToRooms[i]->IsVisited)
            lAllRooms.push_back(NextToRooms[i]);
    }

    return lAllRooms;
}

template<>
Room *Labyrinthe::GetRoomOnPosition<QVector3D>(QVector3D value)
{
    int i = value.x()/RoomSizeInit.x();
    int j = value.z()/RoomSizeInit.y();
    return MazeRooms[i][j];
}

template<>
Room *Labyrinthe::GetRoomOnPosition<QVector2D>(QVector2D value)
{
    int i = value.x()/RoomSizeInit.x();
    int j = value.y()/RoomSizeInit.y();
    return MazeRooms[i][j];
}
