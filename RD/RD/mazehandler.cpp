#include "mazehandler.h"


MazeHandler::MazeHandler(int height, int width)
{

    MazeInformations = new MazeGenerator(width, height, 1 + rand() % width - 2, 0, new QVector<QVector<SquareType>>[height, width]);
    this->CountToExit = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                MazeInformations->Map[i, j].value(SquareType::Wall);
            }
            else
            {
                MazeInformations->Map[i][j].value(SquareType::Unknown);
            }
         }
    }
    ResolveMap = QVector<QVector<SquareType>>[height, width];
 }


void MazeHandler::Generate()
{
        MazeInformations->Map[0, MazeInformations->EntryPositionWidth].value(SquareType::Free);
        QPoint entryPoint = QPoint(1, MazeInformations->EntryPositionWidth);
        Exposed->push_back(entryPoint);

        while (!Exposed->empty()) //CHECK AGAIN
        {
            int random = rand() % Exposed->count();

            QPoint point = Exposed->at(random);

            if (Decide(point))
            {
                Dig(point);
            }
            else
            {
                MazeInformations->Map[point.x(), point.y()].value(SquareType::Wall);
            }
            Exposed->removeAt(random);
        }

        for (int i = 0; i < MazeInformations->Height; i++)
        {
            for (int j = 0; j < MazeInformations->Width; j++)
            {
                if (MazeInformations->Map[i][j] == SquareType::Unknown)
                    MazeInformations->Map[i][j] = SquareType::Wall;
                ResolveMap[i][j] = MazeInformations->Map[i][j];
            }
        }
}
