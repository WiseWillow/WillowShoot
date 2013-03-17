#ifndef POINT_H
#define POINT_H
//
class point
{
private:
    float x;
    float y;
public:
    point(float x_, float y_);//constructor
    point(point& toCopy);//copying constructor
    //TODO  create a constructor generating random point of the plane (from normal distribution)
    ~point();//destructor
    float returnX();//returns first coordinate
    float returnY();//returns second coordinate
    void modifyX(float x_);//modifies first coordinate
    void modifyY(float y_);//modifies second coordinate
    void modifyBothCoordinates(float x_, float y_);//modifies both coordinates coordinate
    float distance(point P);//returns distance between current point and point P
    float distanceSquare(point P);//returns square of the distance between current point and point P (using square of the distance is more efficient)
};

#endif // POINT_H
