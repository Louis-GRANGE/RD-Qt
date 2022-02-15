#include "testcollision.h"

testcollision::testcollision()
{

}

bool testcollision::LinesIntersect(QVector2D A, QVector2D B, QVector2D C, QVector2D D)
{
    QVector2D CmP = QVector2D(C.x() - A.x(), C.y() - A.y());
    QVector2D r = QVector2D(B.x() - A.x(), B.y() - A.y());
    QVector2D s = QVector2D(D.x() - C.x(), D.y() - C.y());

    float CmPxr = CmP.x() * r.y() - CmP.y() * r.x();
    float CmPxs = CmP.x() * s.y() - CmP.y() * s.x();
    float rxs = r.x() * s.y() - r.y() * s.x();

    if(CmPxr == 0)
        return ((C.x() - A.x() < 0) != (C.x() - B.x() < 0)) || ((C.y() - A.y() < 0) != (C.y() - B.y() < 0));

    if(rxs == 0)
        return false;

    float rxsr = 1 / rxs;
    float t = CmPxs * rxsr;
    float u = CmPxr * rxsr;

    return (t >= 0) && (t <= 1) && (u >= 0) && (u <= 1);
}
bool testcollision::SquaresIntersect(QVector2D Amin, QVector2D Amax, QVector2D Bmin, QVector2D Bmax)
{
    if(Amax.y() >= Bmin.y() && Amin.y() <= Bmax.y() && Amax.x() >= Bmin.x() && Amin.x() <= Bmax.x())
        return true;
    else
        return false;
}

bool testcollision::SquareMultiLineIntersect(QVector2D Sqrmin, QVector2D Sqrmax,std::vector<std::vector<QVector2D>> vertices1, QVector2D posV1)
{
    foreach(auto v1, vertices1)
    {
        QVector2D vertA1 = QVector2D(v1[0].x() + posV1.x(), v1[0].y() + posV1.y());
        QVector2D vertA2 = QVector2D(v1[1].x() + posV1.x(), v1[1].y() + posV1.y());
        if(SquareLineIntersect(Sqrmin, Sqrmax,vertA1, vertA2))
            return true;
    }
    return false;
}

bool testcollision::MultiLinesIntersect(std::vector<std::vector<QVector2D>> vertices1, std::vector<std::vector<QVector2D>> vertices2,
                                        QVector2D posV1, QVector2D posV2)
{
    foreach(auto v1, vertices1)
    {
        foreach(auto v2, vertices2)
        {
            QVector2D vertA1 = QVector2D(v1[0].x() + posV1.x(), v1[0].y() + posV1.y());
            QVector2D vertA2 = QVector2D(v1[1].x() + posV1.x(), v1[1].y() + posV1.y());
            QVector2D vertB1 = QVector2D(v2[0].x() + posV2.x(), v2[0].y() + posV2.y());
            QVector2D vertB2 = QVector2D(v2[1].x() + posV2.x(), v2[1].y() + posV2.y());
            if(LinesIntersect(vertA1, vertA2, vertB1, vertB2))
                return true;
        }
    }

    return false;
}

bool testcollision::SquareLineIntersect(QVector2D Sqrmin, QVector2D Sqrmax, QVector2D LnA, QVector2D LnB)
{
    if(LinesIntersect(QVector2D(Sqrmin.x(), Sqrmin.y()), QVector2D(Sqrmax.x(), Sqrmin.y()), LnA, LnB))
        return true;
    if(LinesIntersect(QVector2D(Sqrmax.x(), Sqrmin.y()), QVector2D(Sqrmax.x(), Sqrmax.y()), LnA, LnB))
        return true;
    if(LinesIntersect(QVector2D(Sqrmax.x(), Sqrmax.y()), QVector2D(Sqrmin.x(), Sqrmax.y()), LnA, LnB))
        return true;
    if(LinesIntersect(QVector2D(Sqrmin.x(), Sqrmax.y()), QVector2D(Sqrmin.x(), Sqrmin.y()), LnA, LnB))
        return true;

    return false;
}
