#include "Canvas.h"

Canvas::Canvas()
{
    intersect_points.clear();
	lines.resize(init_list_size);
	lines.clear();
}

Canvas::~Canvas()
{
}

int Canvas::draw(vector<string>* all_geometry_string)
{
	int N = all_geometry_string->size();
	Point* intersecting_point_p;
	for (size_t i = 0; i < N; i++)
	{
		string &s = all_geometry_string->at(i);
		if (s[0] == 'L')
		{
			lines.push_back(Line(s));
		}
		else
		{
			throw "unknown geometry line";
		}
		int n = lines.size();
		for (size_t j = 0; j < n; j++)
		{
			intersecting_point_p = compute_intersection(lines.at(i), lines.at(j));
			if (intersecting_point_p != NULL)
			{
				intersect_points.insert(*intersecting_point_p);
			}
		}
	}
	return intersect_points.size();
}

inline Point* Canvas::compute_intersection(Line& first, Line& second)
{
	double bottom = second.A * first.B - first.A * second.B;
	if (abs(bottom) < eps)
	{
		return NULL;
	}
	else
	{
		double x = (second.B * first.C - second.C * first.B) / bottom;
		double y = (first.A * second.C - second.A * first.C) / bottom;
		return new Point(x, y);
	}	
}