#ifndef TESTCOLLISION_H
#define TESTCOLLISION_H

#include <QVector2D>


class testcollision
{
public:
    testcollision();
    bool SquaresIntersect(QVector2D Amin, QVector2D Amax, QVector2D Bmin, QVector2D Bmax);
    bool LinesIntersect(QVector2D A, QVector2D B, QVector2D C, QVector2D D);
    bool SquareLineIntersect(QVector2D Sqrmin, QVector2D Sqrmax, QVector2D LnA, QVector2D LnB);
    bool MultiLinesIntersect(std::vector<std::vector<QVector2D>> vertices1, std::vector<std::vector<QVector2D>> vertices2,
                             QVector2D posV1, QVector2D posV2);
    bool testcollision::SquareMultiLineIntersect(QVector2D Sqrmin, QVector2D Sqrmax,std::vector<std::vector<QVector2D>> vertices1,
                                                 QVector2D posV1);
};

#endif // TESTCOLLISION_H
