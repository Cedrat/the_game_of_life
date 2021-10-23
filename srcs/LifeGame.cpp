#include "LifeGame.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


Pos convert_pos_1d_in_2d(int actual_cell, int max_x);
int convert_pos_2d_in_1d(Pos position_cell, int max_x);

LifeGame::LifeGame(int nb_rows, int nb_columns, int percent_of_empty_cells) :
_nb_rows(nb_rows), _nb_colums(nb_columns)
{
    std::srand(time(0));
    
    int nb_cases = _nb_colums * _nb_rows;
    int tmp_rand;

    for (int i = 0; i < nb_cases; i++)
    {
        tmp_rand = std::rand() % 100;
        if (tmp_rand <= percent_of_empty_cells)
            _array.push_back(EMPTY_CASE);
        else
            _array.push_back(CELL_CASE);
    } 
}

LifeGame::~LifeGame()
{

}

void LifeGame::printLife()
{
    std::string temp_map;
    for (int x = 0; x < (_nb_colums * _nb_rows); x++)
    {
        temp_map.push_back(_array[x]);
        if ((x % _nb_colums) == _nb_colums -1)
            temp_map += "\n";
    }
    system("clear");
    std::cout << temp_map;
}


int count_close_cells_for_three_cells_in_a_row(Pos position, int nb_columns, std::vector<char> _array)
{
    int count_close_cells = 0;

    for (int i = 0; i < 3; i++)
        {
        if (position.x < 0)
        {
            position.x += nb_columns;
        }
        else if (position.x >= (nb_columns))
        {
            position.x -= (nb_columns);
        }
        if (_array[(convert_pos_2d_in_1d(position, nb_columns))] == CELL_CASE)
        {
            count_close_cells++;
        }
        position.x++;
    }
    return (count_close_cells);
}

/*
    check the numbers of cells arount it.
    if cells is on the edge, count the cells other sides
    return the new state of the cell
*/

char LifeGame::newState(int cell)
{
    Pos position_cell;
    position_cell = convert_pos_1d_in_2d(cell, _nb_colums);

    int count_close_cells = 0;
    position_cell.y -= 1;
    if (position_cell.y < 0)
    {
        position_cell.y += _nb_rows;
    }
    position_cell.x -= 1;
    count_close_cells += count_close_cells_for_three_cells_in_a_row(position_cell, _nb_colums,_array);

    position_cell = convert_pos_1d_in_2d(cell, _nb_colums);
    position_cell.y += 1;
    if (position_cell.y >= (_nb_rows))
    {
        position_cell.y -= _nb_rows;
    }
    position_cell.x -= 1;
    count_close_cells += count_close_cells_for_three_cells_in_a_row(position_cell, _nb_colums,_array);
    
    position_cell = convert_pos_1d_in_2d(cell, _nb_colums);
    position_cell.x -= 1;
    if (position_cell.x < 0)
    {
        position_cell.x += _nb_colums;
    }
    if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums))] == CELL_CASE)
    {
        count_close_cells++;
    }
    position_cell.x += 2;
    if (position_cell.x >= (_nb_colums))
    {
        position_cell.x -= (_nb_colums);
    }
    if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums))] == CELL_CASE)
    {
        count_close_cells++;
    }

    if (count_close_cells == 3)
        return (CELL_CASE);
    else if (count_close_cells == 2)
        return (_array[cell]);
    else
        return (EMPTY_CASE);
}

void LifeGame::cycle()
{
    std::vector<char> new_array;
    for (int x = 0; x < (_nb_colums *_nb_rows); x++)
    {
        new_array.push_back(newState(x));
    }
    _array = new_array;
}
