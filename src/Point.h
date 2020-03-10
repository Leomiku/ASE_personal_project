#include <utility>
#include <memory>
#include <math.h>

#include "float_deal.h"

#ifndef POINT
#define POINT

using std::pair;
using std::memcpy;
using std::abs;

class Point : public pair<double, double>
{
public:
	Point(double x, double y);
	~Point();

	bool operator==(const Point& other) const;
    inline Point operator-(const Point& other) const;
    inline Point operator+(const Point& other) const;

private:

};

namespace std
{
    template<>
    struct hash<Point>
    {
        inline size_t operator()(const Point& h) const
        {
            unsigned long long table_a;
            unsigned long long table_b;
            // use 0x7fffffffffffff00 dropping sign bit to improve effecience. 
            memcpy(&table_a, &h.first, sizeof(double));
            memcpy(&table_b, &h.second, sizeof(double));
            return (table_a & truncate) ^ (table_b & truncate);
        }
    };
}

#endif // !POINT

