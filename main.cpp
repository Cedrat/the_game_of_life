#include <string>
#include <vector>
#include "ArrayLife.hpp"
#include "unistd.h"



int main(int argc, char **argv)
{
    int width = 10;
    int heigth = 10;
    int percent_of_empty_cells = 50;
    int framerate = 30;
    if (argc >= 3)
    {
        width = atoi(argv[1]);
        heigth = atoi(argv[2]);

        if (width <= 0 || heigth <= 0)
        {
            std::cerr << "Need two integers positivs in arguments" << std::endl;
            return 0;
        }
    }
    if (argc >= 4)
    {
        percent_of_empty_cells = atoi(argv[3]);
        if (percent_of_empty_cells <= 0 || percent_of_empty_cells >= 100)
        {
            std::cout << "Please choose a number between 0 and 100" << std::endl;
            return 0;
        }
    }
    if (argc >= 5)
    {
        framerate = 1000000/atoi(argv[4]);
        if (framerate < 0)
        {
            std::cout << "Please choose a position framerate (fps)" << std::endl;
            return 0;
        }
    }
    ArrayLife life(width, heigth, percent_of_empty_cells);
    while (1)
    {
        usleep(framerate);
        life.printLife();
        life.cycle();
    }
}

