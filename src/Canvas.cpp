#include "Canvas.h"

#define LINE_CODE 0
#define CIRCLE_CODE 1

Canvas::Canvas()
{
    intersect_points.clear();
	lines.resize(init_list_size);
	lines.clear();
	circles.resize(init_list_size);
	circles.clear();
}

Canvas::~Canvas()
{
}

size_t Canvas::draw(vector<string>* all_geometry_string)
{
	size_t N = all_geometry_string->size(), n;
	Point* intersecting_point_p;
	int tag;
	Line* line = NULL;
	Circle* circle = NULL;
	Point* ips[2] = { NULL, NULL }; // the return points for two intersectin points
	for (size_t i = 0; i < N; i++)
	{
		string &s = all_geometry_string->at(i);
		if (s[0] == 'L')
		{
			tag = LINE_CODE;
			line = new Line(s);
		}
		else if (s[0] == 'C')
		{
			tag = CIRCLE_CODE;
			circle = new Circle(s);
		}
		else 
		{
			throw "unknown geometry line";
		}
		n = lines.size();
		for (size_t j = 0; j < n; j++)
		{
			if (tag == LINE_CODE)
			{
				intersecting_point_p = line_line_intersection(lines.at(j), line);
				if (intersecting_point_p != NULL)
				{
					intersect_points.insert(*intersecting_point_p);
				}
			}
			else
			{
				 line_circle_intersection(lines.at(j), circle, ips);
				if (ips[0] != NULL)
				{
					intersect_points.insert(*ips[0]);
				}
				if (ips[1] != NULL)
				{
					intersect_points.insert(*ips[1]);
				}
			}
		}
		n = circles.size();
		for (size_t j = 0; j < n; j++)
		{
			if (tag == LINE_CODE)
			{
				line_circle_intersection(line, circles.at(j), ips);
				if (ips[0] != NULL)
				{
					intersect_points.insert(*ips[0]);
				}
				if (ips[1] != NULL)
				{
					intersect_points.insert(*ips[1]);
				}
			}
			else
			{
				circle_circle_intersection(circle, circles.at(j), ips);
				if (ips[0] != NULL)
				{
					intersect_points.insert(*ips[0]);
				}
				if (ips[1] != NULL)
				{
					intersect_points.insert(*ips[1]);
				}
			}
		}
		if (tag == LINE_CODE)
		{
			lines.push_back(line);
		}
		else
		{
			circles.push_back(circle);
		}
	}
	return intersect_points.size();
}

inline Point* Canvas::line_line_intersection(Line* first, Line* second)
{
	double bottom = second->A * first->B - first->A * second->B;
	if (abs(bottom) < eps)
	{
		return NULL;
	}
	else
	{
		double x = (second->B * first->C - second->C * first->B) / bottom;
		double y = (first->A * second->C - second->A * first->C) / bottom;
		return new Point(x, y);
	}	
}

inline void Canvas::line_circle_intersection(Line* line, Circle* circle, Point* ips[])
{
	Point* c1 = NULL, * c2 = NULL;
	double d = abs(line->A * circle->x_0 + line->B * circle->y_0 + line->C) / sqrt(line->A * line->A + line->B * line->B);
	if (fequal(d, circle->r))
	{
		double B;
		double square_add = circle->x_0 * circle->x_0 + circle->y_0 * circle->y_0 - circle->r * circle->r;
		double i_1_x, i_1_y;
		if (line->A == 0)
		{
			B = -2 * circle->x_0;
			i_1_x = -0.5 * B;
			c1 = new Point(i_1_x, -line->C);
		}
		else if (line->B == 0)
		{
			B = -2 * circle->y_0;
			i_1_y = -0.5 * B;
			c1 = new Point(-line->C, i_1_y);
		}
		else
		{
			B = (2 * line->A * line->C - 2 * circle->x_0 - 2 * line->A * circle->y_0) / (line->A * line->A + 1);
			i_1_x = -0.5 * B;
			i_1_y = line->A * i_1_x + line->C;
			c1 = new Point(i_1_x, i_1_y);
		}
	}
	else if (d < circle->r)
	{
		double B, C, deta;
		double square_add = circle->x_0 * circle->x_0 + circle->y_0 * circle->y_0 - circle->r * circle->r;
		double i_1_x, i_1_y, i_2_x, i_2_y;
		if (line->A == 0)
		{
			B = -2 * circle->x_0;
			C = square_add + 2 * line->C * circle->y_0 + line->C * line->C;
			deta = sqrt(0.25 * B * B - C);
			i_1_x = -0.5 * B + deta;
			i_2_x = -0.5 * B - deta;
			c1 = new Point(i_1_x, -line->C);
			c2 = new Point(i_2_x, -line->C);
		}
		else if (line->B == 0)
		{
			B = -2 * circle->y_0;
			C = square_add + 2 * line->C * circle->x_0 + line->C * line->C;
			deta = sqrt(0.25 * B * B - C);
			i_1_y = -0.5 * B + deta;
			i_2_y = -0.5 * B - deta;
			c1 = new Point(-line->C, i_1_y);
			c2 = new Point(-line->C, i_2_y);
		}
		else
		{
			B = (2 * line->A * line->C - 2 * circle->x_0 - 2 * line->A * circle->y_0) / (line->A * line->A + 1);
			C = (square_add + line->C * line->C - 2 * line->C * circle->y_0) / (line->A * line->A + 1);
			deta = sqrt(0.25 * B * B - C);
			i_1_x = -0.5 * B + deta;
			i_2_x = -0.5 * B - deta;
			i_1_y = line->A * i_1_x + line->C;
			i_2_y = line->A * i_2_x + line->C;
			c1 = new Point(i_1_x, i_1_y);
			c2 = new Point(i_2_x, i_2_y);
		}
	}
	ips[0] = c1;
	ips[1] = c2;
}

inline void Canvas::circle_circle_intersection(Circle* c_1, Circle* c_2, Point* ips[])
{
	Point* ip_1 = NULL, * ip_2 = NULL;
	double r_add = c_1->r + c_2->r, r_sub = abs(c_1->r - c_2->r);
	double c_dis = sqrt((c_1->x_0 - c_2->x_0) * (c_1->x_0 - c_2->x_0) + (c_1->y_0 - c_2->y_0) * (c_1->y_0 - c_2->y_0));
	if (fequal(r_add, c_dis))
	{
		ip_1 = new Point((c_1->x_0 * c_2->r + c_2->x_0 * c_1->r) / (c_1->r + c_2->r),
			(c_1->y_0 * c_2->r + c_2->y_0 * c_1->r) / (c_1->r + c_2->r));
	}
	else if (fequal(r_sub, c_dis))
	{
		Circle *small, *large;
		if (c_1->r > c_2->r)
		{
			small = c_2;
			large = c_1;
		}
		else
		{
			small = c_1;
			large = c_2;
		}
		double c12_v_x = small->x_0 - large->x_0;
		double c12_v_y = small->y_0 - large->y_0;
		double riot = large->r / sqrt(c12_v_x * c12_v_x + c12_v_y * c12_v_y);
		ip_1 = new Point(large->x_0 + riot * c12_v_x, large->y_0 + riot * c12_v_y);
	}
	else if (c_dis > r_sub && c_dis < r_add)
	{
		double c12_v_x = c_2->x_0 - c_1->x_0;
		double c12_v_y = c_2->y_0 - c_1->y_0;
		double cos_ceta = (c_1->r * c_1->r + c_dis * c_dis - c_2->r * c_2->r) / (2 * c_1->r * c_dis);
		double sin_ceta = sqrt(1 - cos_ceta * cos_ceta);
		double sin_alpa = c12_v_y / sqrt(c12_v_x * c12_v_x + c12_v_y * c12_v_y);
		double cos_alpa = c12_v_x / sqrt(c12_v_x * c12_v_x + c12_v_y * c12_v_y);
		double sin_1 = sin_alpa * cos_ceta + cos_alpa * sin_ceta;
		double cos_1 = cos_alpa * cos_ceta - sin_alpa * sin_ceta;
		double sin_2 = sin_alpa * cos_ceta - cos_alpa * sin_ceta;
		double cos_2 = cos_alpa * cos_ceta + sin_alpa * sin_ceta;
		ip_1 = new Point(c_1->x_0 + c_1->r * cos_1, c_1->y_0 + c_1->r * sin_1);
		ip_2 = new Point(c_1->x_0 + c_1->r * cos_2, c_1->y_0 + c_2->r * sin_2);
	}
	ips[0] = ip_1;
	ips[1] = ip_2;
}