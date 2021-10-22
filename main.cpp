#include <string>
#include <vector>
#include "ArrayLife.hpp"
#include "unistd.h"

int main()
{
   ArrayLife life(50, 50);

    life.addRandomLife();
    sleep(1);
    life.addRandomLife();
    sleep(1);
    life.addRandomLife();
    life.printLife();
    while (1)
    {
        usleep(100000);
        life.cycle();
        life.printLife();
    }
}

