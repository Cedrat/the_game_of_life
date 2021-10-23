#include "LifeGame.hpp"

Pos convert_pos_1d_in_2d(int actual_cell, int max_x)
{
    Pos position;

    position.x = actual_cell % max_x;
    position.y = actual_cell / max_x;

    return (position);
}

int convert_pos_2d_in_1d(Pos position_cell, int max_x)
{
    return (position_cell.x + max_x * position_cell.y);
}