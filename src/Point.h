#include <utility>
#include <memory>
#include <math.h>

#ifndef POINT
#define POINT

#define eps 1e-12
#define truncate 0xffffffffffffff00 

using std::pair;
using std::memcpy;
using std::abs;

class Point : public pair<double, double>
{
public:
	Point(double x, double y);
	~Point();

	bool operator==(const Point& other) const;

private:

};

namespace std
{
    template<>
    struct hash<Point>
    {
        size_t operator()(const Point& h) const
        {
            unsigned long long table_a;
            unsigned long long table_b;
            double x = abs(h.first);
            double y = abs(h.second);
            memcpy(&table_a, &x, sizeof(double));
            memcpy(&table_b, &y, sizeof(double));
            return (table_a & truncate) ^ (table_b & truncate);
        }
    };
}

#endif // !POINT

