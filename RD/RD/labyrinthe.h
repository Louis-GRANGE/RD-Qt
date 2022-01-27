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
    QList<Room> lRoom;
};

#endif // LABYRINTHE_H
