#include "room.h"
#include "collision.h"
#include "collectable.h"

Room::Room(QVector2D size, QVector2D position)
{
    Size = size;
    RelativePosition = position;
    WorldPosition = QVector2D(position.x() * Size.x() + Size.x()/2, position.y() * Size.y() + Size.y()/2);
    transform.position = QVector3D(WorldPosition.x(), -5, WorldPosition.y());

    //Singleton<GLDisplayWidget>::getInstance().AddCObject(this);
    std::vector<QVector3D> vertices = {
        QVector3D(- Size.x() / 2, 0, - Size.y() / 2), //TOP LEFT
        QVector3D(+ Size.x() / 2, 0, - Size.y() / 2), //TOP RIGHT
        QVector3D(- Size.x() / 2, 0, + Size.y() / 2), //BOTTOM LEFT
        QVector3D(+ Size.x() / 2, 0, + Size.y() / 2), //BOTTOM RIGHT
        //UP for Walls
        QVector3D(- Size.x() / 2, 6 , - Size.y() / 2), //UP TOP LEFT
        QVector3D(+ Size.x() / 2, 6 , - Size.y() / 2), //UP TOP RIGHT
        QVector3D(- Size.x() / 2, 6 , + Size.y() / 2), //UP BOTTOM LEFT
        QVector3D(+ Size.x() / 2, 6 , + Size.y() / 2)  //UP BOTTOM RIGHT
    };
    std::vector<int> triangles = {1, 2, 4, 1, 4, 3};

    std::vector<QVector3D> colors = {GroundColor, GroundColor};

    drawObject.data = {vertices, triangles, colors};


    if(rand() % 6 == 0)
    {
        Collectable* col = new Collectable();
        col->transform.position = transform.position + QVector3D(0,2,0);
    }
}

void Room::DrawRoom(QGraphicsScene *scene)
{
    if(HaveWallUP)
    {
        drawObject.data.triangles.insert(drawObject.data.triangles.end(), {5,6,2,5,2,1});
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
    }
    if(HaveWallLEFT)
    {
        drawObject.data.triangles.insert(drawObject.data.triangles.end(), {5,7,1,7,3,1});
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
    }
    if(HaveWallRIGHT)
    {
        drawObject.data.triangles.insert(drawObject.data.triangles.end(), {6,4,8,6,2,4});
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
    }
    if(HaveWallDOWN)
    {
        drawObject.data.triangles.insert(drawObject.data.triangles.end(), {7,8,4,7,4,3});
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
        drawObject.data.colors.insert(drawObject.data.colors.end(), WallsColor);
    }


    /*
    QGraphicsRectItem * rect = new QGraphicsRectItem();


    rect->setRect(Position.x(),Position.y(),Size.x(),Size.y());

    if(CanEnter)
    {
        rect->setBrush(Qt::red);
    }

    scene->addItem(rect);*/

    InitColliders();
}

void Room::DrawRoom2D(QGraphicsScene *scene)
{
    if(!Is2DDraw)
    {
        if(HaveWallUP)
        {
            DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()-Size.y()/2), scene, WallsColor);
        }
        if(HaveWallLEFT)
        {
            DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()+Size.y()/2), scene, WallsColor);
        }
        if(HaveWallRIGHT)
        {
            DrawWall(QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()-Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()+Size.y()/2), scene, WallsColor);
        }
        if(HaveWallDOWN)
        {
            DrawWall(QVector2D(WorldPosition.x()-Size.x()/2, WorldPosition.y()+Size.y()/2), QVector2D(WorldPosition.x()+Size.x()/2, WorldPosition.y()+Size.y()/2), scene, WallsColor);
        }
        Is2DDraw = true;
        //scene->update();
    }
}

void Room::InitColliders()
{
    collision = Collision();
    collision.myCollisionType = CollisionType::Static;
    collision.myColliderType = ColliderType::MultiLine;

    if(HaveWallUP)
        collision.vertices.push_back({QVector2D(- Size.x() / 2 , - Size.y() / 2), QVector2D(+ Size.x() / 2 , - Size.y() / 2)});
    if(HaveWallRIGHT)
        collision.vertices.push_back({QVector2D(+ Size.x() / 2 , - Size.y() / 2), QVector2D(+ Size.x() / 2 , + Size.y() / 2)});
    if(HaveWallDOWN)
        collision.vertices.push_back({QVector2D(+ Size.x() / 2 , + Size.y() / 2), QVector2D(- Size.x() / 2 , + Size.y() / 2)});
    if(HaveWallLEFT)
        collision.vertices.push_back({QVector2D(- Size.x() / 2 , + Size.y() / 2), QVector2D(- Size.x() / 2 , - Size.y() / 2)});
}

void Room::DrawWall(QVector2D p1,QVector2D p2, QGraphicsScene *scene, QVector3D color)
{
    QGraphicsLineItem * Wall = new QGraphicsLineItem(p1.x(), p1.y(), p2.x(), p2.y());
    Wall->setPen(QPen(QColor(color.x()*255, color.y()*255, color.z()*255), 5));
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
