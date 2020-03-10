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
    return (fequal(first, other.first) && fequal(second, other.second));
}

inline Point Point::operator-(const Point& other) const
{
    return Point(first - other.first, second - other.second);
}

inline Point Point::operator+(const Point& other) const
{
    return Point(first + other.first, second + other.second);
}