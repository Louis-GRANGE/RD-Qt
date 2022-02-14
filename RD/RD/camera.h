#ifndef CAMERA_H
#define CAMERA_H
#include "transform.h"

class Camera
{
public:
    Camera();
    Transform transform;
    bool Is3DView = true;
    void ToggleView();

    Transform TopViewOffset{ QVector3D(0, 5, 0), QVector3D(0, 0, 0)};
    Transform FPSViewOffset{ QVector3D(0, 5, 0), QVector3D(0, 0, 0)};
    Transform Offset = TopViewOffset;
};

#endif // CAMERA_H
