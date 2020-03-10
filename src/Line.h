#include <string>
#include <ctype.h>

#ifndef LINE
#define LINE

using std::string;
using std::stoi;
using std::isdigit;

class Line
{
public:
	Line();
	Line(string &s);
	~Line();

	double A;
	double B;
	double C;
private:
};
#endif // !LINE

