#include <string>
#include <fstream>
#include <vector>

#ifndef IO_CLASS
#define IO_CLASS

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
using std::getline;
using std::stoi;

class IO_class
{
public:
	IO_class(int argc, char* argv[]);
	~IO_class();
	vector<string>* read();
	void write(int n);

private:
	string in_path;
	string out_path;
	ifstream in;
	ofstream out;
	vector<string> all_geometry_string;
};

#endif // !IO_CLASS
