#include "camera.h"

Camera::Camera()
{

}

void Camera::ToggleView()
{
    IsTopView = !IsTopView;

    if(IsTopView)
        Offset = TopViewOffset;
    else
        Offset = FPSViewOffset;
}
