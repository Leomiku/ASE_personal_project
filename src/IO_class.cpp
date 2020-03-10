#include "IO_class.h"

IO_class::IO_class(int argc, char* argv[])
{
	string a, b;
	for (size_t i = 1; i < argc; i++)
	{
		a = string(argv[i]);
		b = string(argv[i + 1]);
		if (a == "-i")
		{
			in_path = b;
			i++;
		}
		else if (a == "-o")
		{
			out_path = b;
			i++;
		}
	}
	in.open(in_path);
	out.open(out_path);
}

IO_class::~IO_class()
{
}

vector<string> *IO_class::read()
{
	int N;
	string s;
	getline(in, s);
	N = stoi(s);
	all_geometry_string.resize(N);
	all_geometry_string.clear();
	while (getline(in, s))
	{
		all_geometry_string.push_back(s);
	}
	return &all_geometry_string;
}

void IO_class::write(size_t n)
{
	out << n << endl;
}