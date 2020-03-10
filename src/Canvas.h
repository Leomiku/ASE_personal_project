#include <vector>
#include <unordered_set>
#include <utility>
#include  <cmath>

#include "Point.h"
#include "Line.h"
#include "Circle.h"

#ifndef CANVAS
#define CANVAS

using std::unordered_set;
using std::vector;
using std::pair;
using std::sqrt;
using std::abs;
using std::sin;
using std::cos;
using std::acos;
using std::asin;
using std::atan;

class Canvas
{
public:

	const int init_list_size = 10000;

	Canvas();
	~Canvas();

	size_t draw(vector<string>* all_geometry_string);

private:
	unordered_set<Point> intersect_points;
	vector<Line*> lines;
	vector<Circle*> circles;
	inline Point* line_line_intersection(Line* a, Line* b);
	inline void line_circle_intersection(Line* line, Circle* circle, Point *ips[]);
	inline void circle_circle_intersection(Circle* c_1, Circle* c_2, Point* ips[]);
};

#endif // !CANVAS

