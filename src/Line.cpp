#include "Line.h"

#define x_1 number[0]
#define y_1 number[1]
#define x_2 number[2]
#define y_2 number[3]

Line::Line() {}

Line::Line(string &s)
{
    // x_1 : 0, y_1 : 1. x_2 : 2, y_2 : 3
    int number[4];
    int begin = -1, stt = -1, n = s.length();
    size_t i;
    for (i = 0; i < n; i++)
    {
        begin = begin;
        if (isdigit(s[i]) && begin == -1)
        {
            begin = i;
        }
        else if (!isdigit(s[i]) && begin != -1)
        {
            stt++;
            if (stt < 4)
            {
                number[stt] = stoi(s.substr(begin, i - begin));
            }
            else
            {
                throw "the input " + s + " is wrong for line!";
            }
            begin = -1;
        }
    }
    if (begin != -1)
    {
        stt++;
        number[stt] = stoi(s.substr(begin, i - begin));
    }
    if (stt < 3)
    {
        throw "the input " + s + " is wrong for line!";
    }
    if (y_1 == y_2)
    {
        A = 0;
        B = 1;
        C = -y_1;
    }
    else if (x_1 == x_2)
    {
        A = 1;
        B = 0;
        C = -x_1;
    }
    else
    {
        A = (double)(y_1 - y_2) / (x_1 - x_2);
        B = -1;
        C = (double)(x_1 * y_2 - x_2 * y_1) / (x_1 - x_2);
    }
}

Line::~Line()
{
}