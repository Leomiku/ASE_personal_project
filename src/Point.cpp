#include "Point.h"

Point::Point(double x, double y)
{
    first = x;
    second = y;
}

Point::~Point()
{

}

bool Point::operator==(const Point& other) const
{
    return (abs(first - other.first) < eps && abs(second - other.second) < eps);
}