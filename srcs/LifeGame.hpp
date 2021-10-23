#ifndef LIFEGAME_HPP
# define LIFEGAME_HPP

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

#define EMPTY_CASE '.'
#define CELL_CASE 'X'

struct Pos{
    int x;
    int y;
};

class LifeGame
{
    private :
        std::vector<char> _array;
        int _nb_rows;
        int _nb_colums;

        void insertLife(Pos position, std::string sequence);
        char newState(int cell);
    public :
        LifeGame(int nb_rows, int nb_columns, int percent_of_empty_cells);
        ~LifeGame();

        void addRandomLife();
        void printLife();
        void cycle();

};

#endif