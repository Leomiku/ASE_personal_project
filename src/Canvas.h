#include <vector>
#include <unordered_set>

#include "Point.h"
#include "Line.h"
#include "Circle.h"

#ifndef CANVAS
#define CANVAS

using std::unordered_set;
using std::vector;

class Canvas
{
public:
	const int init_list_size = 10000;

	Canvas();
	~Canvas();

	int draw(vector<string>* all_geometry_string);

private:
	unordered_set<Point> intersect_points;
	vector<Line> lines;
	inline Point* compute_intersection(Line& a, Line& b);
};

#endif // !CANVAS

