#include <string>

#ifndef CIRCLE
#define CIRCLE

using std::string;

class Circle
{
public:
	Circle(string &s);
	~Circle();

	double x_0;
	double y_0;
	double r;
private:
};

#endif // !CIRCLE

