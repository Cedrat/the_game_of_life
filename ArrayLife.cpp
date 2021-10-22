#include "ArrayLife.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>


Pos convert_pos_1d_in_2d(int actual_cell, int max_x, int max_y);
int convert_pos_2d_in_1d(Pos position_cell, int max_x, int max_y);

ArrayLife::ArrayLife(int nb_rows, int nb_columns) : _nb_rows(nb_rows), _nb_colums(nb_columns)
{
    int nb_cases = _nb_colums * _nb_rows;

    std::vector<char>::iterator it_begin = _array.begin();
    
    _array.insert(it_begin, nb_cases, EMPTY_CASE);
}

ArrayLife::~ArrayLife()
{

}

void ArrayLife::printLife()
{
    std::string temp_map;
    for (int x = 0; x < (_nb_colums * _nb_rows); x++)
    {
        temp_map.push_back(_array[x]);
        if ((x % _nb_colums) == _nb_colums -1)
            temp_map += "\n";
    }
    std::cout << temp_map << std::endl;
}

static std::string generate_random_sequence()
{
    std::srand(time(0));
    std::string sequence(EMPTY_CASE, 9);

    char life[] = {EMPTY_CASE, CELL_CASE};

    for (int i = 0; i < 9; i++)
    {
        sequence[i] = life[std::rand()%2];
    }
    return (sequence);
}

static Pos choose_random_insert(int max_width, int max_heigth)
{
    std::srand(time(0));
    Pos pos;

    pos.x = std::rand() % (max_width);
    pos.y = std::rand() % (max_heigth -2);

    return (pos);
}

void ArrayLife::addRandomLife()
{
    std::string random_sequence = generate_random_sequence();

    Pos pos = choose_random_insert(_nb_colums, _nb_rows);

    insertLife(pos, random_sequence);
}

void ArrayLife::insertLife(Pos pos, std::string random_sequence)
{
    _array[pos.x * pos.y] = random_sequence[0];
    _array[pos.x * pos.y + 1] = random_sequence[1];
    _array[pos.x * pos.y + 2] = random_sequence[2];
    _array[pos.x * pos.y + _nb_colums] = random_sequence[3];
    _array[pos.x * pos.y + _nb_colums + 1] = random_sequence[4];
    _array[pos.x * pos.y + _nb_colums + 2] = random_sequence[5];
    _array[pos.x * pos.y + 2 * _nb_colums] = random_sequence[6];
    _array[pos.x * pos.y + 2 * _nb_colums + 1] = random_sequence[7];
    _array[pos.x * pos.y + 2 * _nb_colums + 2] = random_sequence[8];
}

/*
    check the numbers of cells arount it.
    if cells is on the edge, count the cells other sides
    return the new state of the cell
*/

//cell - 1 - nb_columns
char ArrayLife::newState(int cell)
{
    Pos position_cell;
    position_cell = convert_pos_1d_in_2d(cell, _nb_colums, _nb_rows);

    int count_close_cells = 0;
    position_cell.y -= 1;
    if (position_cell.y < 0)
    {
        position_cell.y += _nb_rows;
    }
    position_cell.x -= 1;
    for (int i = 0; i < 3; i++)
    {
        if (position_cell.x < 0)
        {
            position_cell.x += _nb_colums;
        }
        else if (position_cell.x >= (_nb_colums))
        {
            position_cell.x -= (_nb_colums);
        }
        if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums, _nb_rows))] == CELL_CASE)
        {
            count_close_cells++;
        }
        position_cell.x++;
    }

    position_cell = convert_pos_1d_in_2d(cell, _nb_colums, _nb_rows);
    position_cell.y += 1;
    if (position_cell.y >= (_nb_rows))
    {
        position_cell.y -= _nb_rows;
    }
    position_cell.x -= 1;
    for (int i = 0; i < 3; i++)
    {
        if (position_cell.x < 0)
        {
            position_cell.x += _nb_colums;
        }
        else if (position_cell.x >= (_nb_colums))
        {
            position_cell.x -= (_nb_colums);
        }
        if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums, _nb_rows))] == CELL_CASE)
        {
            count_close_cells++;
        }
        position_cell.x++;
    }
    position_cell = convert_pos_1d_in_2d(cell, _nb_colums, _nb_rows);
    position_cell.x -= 1;
    if (position_cell.x < 0)
    {
        position_cell.x += _nb_colums;
    }
    if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums, _nb_rows))] == CELL_CASE)
    {
        count_close_cells++;
    }
    position_cell.x += 2;
    if (position_cell.x >= (_nb_colums))
    {
        position_cell.x -= (_nb_colums);
    }
    if (_array[(convert_pos_2d_in_1d(position_cell, _nb_colums, _nb_rows))] == CELL_CASE)
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

void ArrayLife::cycle()
{
    std::vector<char> new_array;
    for (int x = 0; x < (_nb_colums *_nb_rows); x++)
    {
        new_array.push_back(newState(x));
    }
    _array = new_array;
}