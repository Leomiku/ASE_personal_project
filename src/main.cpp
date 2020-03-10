#include "Canvas.h"
#include "IO_class.h"

int main(int argc, char *argv[])
{
    IO_class io(argc, argv);
    vector<string> * all_geometry_string = io.read();
    Canvas canvas = Canvas();
    int n = canvas.draw(all_geometry_string);
    io.write(n);
}