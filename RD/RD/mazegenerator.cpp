#include "mazegenerator.h"

MazeGenerator::MazeGenerator()
{

}

MazeGenerator::MazeGenerator(int _Width, int _Height, int _EntryPositionWidth, int _ExitPositionWidth, QVector<QVector<SquareType> > *_Map)
{
    Width = _Width;
    Height = _Height;
    EntryPositionWidth = _EntryPositionWidth;
    ExitPositionWidth = _ExitPositionWidth;
    Map = _Map;
}
