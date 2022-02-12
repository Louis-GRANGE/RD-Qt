#ifndef MAZEHANDLER_H
#define MAZEHANDLER_H
#include "mazegenerator.h"
#include "QPoint"


class MazeHandler
{
public:
    const int DefaultWidth = 40;
    const int DefaultHeight = 20;

    MazeGenerator* MazeInformations;
    int CountToExit;
    QVector<QPoint>* Exposed = new QVector<QPoint>();
    QVector<QVector<SquareType>> ResolveMap;

    MazeHandler(int height, int width);
    void Generate();
};

#endif // MAZEHANDLER_H
