#include "labyrinthe.h"

Labyrinthe::Labyrinthe(QGraphicsView * view, QVector2D size)
{
    Size = size;
    //lRoom = new QList<Room>();
    QVector2D RoomSizeInit = QVector2D(25, 25);
    QGraphicsScene * scene = new QGraphicsScene();

    for(int x = 0; x < Size.x(); x++)
    {
        for(int y = 0; y < Size.y(); y++)
        {
            Room tmp = Room(QVector2D(RoomSizeInit.x(), RoomSizeInit.y()), QVector2D(RoomSizeInit.x() * x, RoomSizeInit.y() * y), rand()%2 == 0);
            tmp.DrawRoom(scene);
            lRoom.push_back(tmp);
        }
    }

    view = new QGraphicsView(scene);
    view->show();
}
