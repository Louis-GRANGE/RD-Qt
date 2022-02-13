#include "room.h"

Room::Room(QVector2D size, QVector2D position)
{
    Size = size;
    RelativePosition = position;
    WorldPosition = QVector2D(position.x() * size.x() + size.x()/2, position.y() * size.y() + size.y()/2);

    //Singleton<GLDisplayWidget>::getInstance().AddCObject(this);

    std::vector<QVector3D> vertices = { //REMETTRE Diviser par 2
        QVector3D(WorldPosition.x() - size.x() / 3, -10, WorldPosition.y() - size.y() / 3), //TOP LEFT
        QVector3D(WorldPosition.x() + size.x() / 3, -10, WorldPosition.y() - size.y() / 3), //TOP RIGHT
        QVector3D(WorldPosition.x() - size.x() / 3, -10, WorldPosition.y() + size.y() / 3), // BOTTOM LEFT
        QVector3D(WorldPosition.x() + size.x() / 3, -10, WorldPosition.y() + size.y() / 3)  // BOTTOM RIGHT
    };
    std::vector<int> triangles = {1, 2, 4, 1, 4, 3};

    std::vector<QVector3D> colors = {QVector3D(1,0.8,0), QVector3D(0.2 ,0.8,0)};

    drawObject.data = {vertices, triangles, colors};
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
