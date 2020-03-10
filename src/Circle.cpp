#include "Circle.h"

Circle::Circle(string &s)
{
    // x_1 : 0, y_0 : 1. r : 2
    int number[3];
    int begin = -1, stt = -1, n = (int) s.length();
    int i;
    for (i = 0; i < n; i++)
    {
        if ((isdigit(s[i]) || s[i] == '-') && begin == -1)
        {
            begin = i;
        }
        else if (!isdigit(s[i]) && begin != -1)
        {
            stt++;
            if (stt < 3)
            {
                number[stt] = stoi(s.substr(begin, (long long)i - begin));
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
        number[stt] = stoi(s.substr(begin, (long long)i - begin));
    }
    if (stt < 2)
    {
        throw "the input " + s + " is wrong for line!";
    }
    x_0 = number[0];
    y_0 = number[1];
    r = number[2];
}

Circle::~Circle()
{
}