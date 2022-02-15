#pragma once
#include "collision.h"

Collision::Collision()
{

}

bool Collision::checkAllCollisions(QVector3D newMovement)
{
    /*QList<CObject*> assets = Singleton<GLDisplayWidget>::getInstance().assets;
    foreach(auto asset, assets)
    {
        if(collision.checkCollision(newMovement, asset->collision))
            return true;
    }*/
    return true;
}

bool Collision::checkCollision(QVector3D newMovement, Collision target, QVector2D pos, QVector2D targetpos)
{
    switch (myColliderType) {
    case ColliderType::MultiLine:
        switch (target.myColliderType){
            case ColliderType::MultiLine:
                return myTestCollision.MultiLinesIntersect(vertices, target.vertices, pos, targetpos);
                break;
            case ColliderType::Box:
                // to define
                break;
            case ColliderType::Line:
                // to define
                break;}
        break;
    case ColliderType::Box:
        switch (target.myColliderType){
            case ColliderType::MultiLine:
                return myTestCollision.SquareMultiLineIntersect(QVector2D(min.x() + pos.x(), min.z()+ pos.y()),
                                                                QVector2D(max.x() + pos.x(), max.z() + pos.y()),
                                                                target.vertices, targetpos);
                break;
            case ColliderType::Box:
                return myTestCollision.SquaresIntersect(QVector2D(min.x() + pos.x(), min.z()+ pos.y()),
                                 QVector2D(max.x() + pos.x(), max.z() + pos.y()),
                                 QVector2D(target.min.x() + targetpos.x(), target.min.z() + targetpos.y()),
                                 QVector2D(target.max.x() + targetpos.x(), target.max.z() + targetpos.y()));
                break;
            case ColliderType::Line:
                return myTestCollision.SquareLineIntersect(QVector2D(min.x(), min.z()), QVector2D(max.x(), max.z()),
                                    QVector2D(target.min.x(), target.min.z()), QVector2D(target.max.x(), target.max.z()));
                break;}
        break;
    case ColliderType::Line:
        switch (target.myColliderType){
            case ColliderType::MultiLine:
                // to define
                break;
            case ColliderType::Box:
                // to define
                break;
            case ColliderType::Line:
                return myTestCollision.LinesIntersect(QVector2D(min.x(), min.z()), QVector2D(max.x(), max.z()),
                               QVector2D(target.min.x(), target.min.z()), QVector2D(target.max.x(), target.max.z()));
                break;}
        break;
    }

    return false;
}
