#include "Canvas.h"
#include "IO_class.h"

size_t run(int argc, char* argv[])
{
    IO_class io(argc, argv);
    vector<string>* all_geometry_string = io.read();
    Canvas canvas = Canvas();
    size_t n = canvas.draw(all_geometry_string);
    io.write(n);
    return n;
}

int main(int argc, char *argv[])
{
    run(argc, argv);
    return 0;
}