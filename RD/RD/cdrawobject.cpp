#include "cdrawobject.h"

cDrawObject::cDrawObject()
{

}

cDrawObject::~cDrawObject()
{
    data = {{},{},{}};
}

cDrawObject::cDrawObject(modele _data)
{
    data = _data;
}
