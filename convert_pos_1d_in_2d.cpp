#include "ArrayLife.hpp"

Pos convert_pos_1d_in_2d(int actual_cell, int max_x, int max_y)
{
    Pos position;

    position.x = actual_cell % max_x;
    position.y = actual_cell / max_x;

    return (position);
}

int convert_pos_2d_in_1d(Pos position_cell, int max_x, int max_y)
{
    return (position_cell.x + max_x * position_cell.y);
}

// int main()
// {
//     Pos pos;

//     for (size_t i = 0; i < 12; i++)
//     {
//        pos =  convert_pos_1d_in_2d(i, 4, 3);
//        std::cout << convert_pos_2d_in_1d(pos, 4, 3) << std::endl;;
//     }
// }