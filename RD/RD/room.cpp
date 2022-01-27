#include "room.h"

Room::Room(QVector2D size, QVector2D position, bool canEnter)
{
    Size = size;
    Position = QVector2D(position.x() + size.x()/2, position.y() + size.y()/2);
    CanEnter = canEnter;
}

void Room::DrawRoom(QGraphicsScene *scene)
{
    QGraphicsRectItem * rect = new QGraphicsRectItem();

    rect->setRect(Position.x(),Position.y(),Size.x(),Size.y());

    if(CanEnter)
    {
        rect->setBrush(Qt::red);
    }

    scene->addItem(rect);
}
