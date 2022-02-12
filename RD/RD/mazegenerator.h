#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H
#include <QVector>

enum SquareType
{
    Wall = '#',
    Free = '.',
    CurrentPos = '0',
    Path = 'o',
    Unknown = '?',
    Explored = '*'
};

class MazeGenerator
{
public:
    MazeGenerator();
    MazeGenerator(int _Width, int _Height, int _EntryPositionWidth, int _ExitPositionWidth, QVector<QVector<SquareType>>* _Map);
    int Width;
    int Height;
    int EntryPositionWidth;
    int ExitPositionWidth;
    QVector<QVector<SquareType>> Map;
};

#endif // MAZEGENERATOR_H
