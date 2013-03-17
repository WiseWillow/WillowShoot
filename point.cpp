#include "point.h"
#include <math.h>

point::point(float x_, float y_)
{
    x=x_;
    y=y_;
}
point::point(point& toCopy)
{
    x=toCopy.x;
    y=toCopy.y;
}
point::~point()
{
    ;
}
float point::returnX()
{
    return x;
}
float point::returnY()
{
    return y;
}
void point::modifyX(float x_)
{
    x=x_;
}
void point::modifyY(float y_)
{
    y=y_;
}
void point::modifyBothCoordinates(float x_, float y_)
{
    x=x_;
    y=y_;
}
float point::distance(point P)
{
    return sqrt((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y));
}
float point::distanceSquare(point P)
{
    return (x-P.x)*(x-P.x)+(y-P.y)*(y-P.y);
}
