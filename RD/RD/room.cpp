#include "room.h"

Room::Room(QVector2D size, QVector2D position)
{
    Size = size;
    RelativePosition = position;
    WorldPosition = QVector2D(position.x() * size.x() + size.x()/2, position.y() * size.y() + size.y()/2);
}

void Room::DrawRoom(QGraphicsScene *scene)
{
    if(HaveWallUP)
        DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()-Size.y()/2), scene, Qt::green);
    if(HaveWallLEFT)
        DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()+Size.y()/2), scene, Qt::blue);
    if(HaveWallRIGHT)
        DrawWall(QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()+Size.y()/2), scene, Qt::darkBlue);
    if(HaveWallDOWN)
        DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()+Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()+Size.y()/2), scene, Qt::darkGreen);

    /*
    QGraphicsRectItem * rect = new QGraphicsRectItem();


    rect->setRect(Position.x(),Position.y(),Size.x(),Size.y());

    if(CanEnter)
    {
        rect->setBrush(Qt::red);
    }

    scene->addItem(rect);*/
}

void Room::DrawWall(QVector2D p1,QVector2D p2, QGraphicsScene *scene, Qt::GlobalColor color)
{
    QGraphicsLineItem * Wall = new QGraphicsLineItem(p1.x(), p1.y(), p2.x(), p2.y());
    Wall->setPen(QPen(color, 5));
    scene->addItem(Wall);
}

int Room::NumberOfWalls()
{
    int nb = 0;
    if(HaveWallUP) nb = nb + 1;
    if(HaveWallDOWN) nb = nb + 1;
    if(HaveWallLEFT) nb = nb + 1;
    if(HaveWallRIGHT) nb = nb + 1;
    return nb;
}
