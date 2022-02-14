#include "camera.h"

Camera::Camera()
{

}

void Camera::ToggleView()
{
    Is3DView = !Is3DView;

    if(Is3DView)
        Offset = TopViewOffset;
    else
        Offset = FPSViewOffset;
}
