#ifndef CINPUTCONTROLLER_H
#define CINPUTCONTROLLER_H
#include <QKeyEvent>

class CInputController
{
public:
    CInputController();
    QVector3D * newMovement;
    void keyPressEvent(QKeyEvent *event);
};

#endif // CINPUTCONTROLLER_H
