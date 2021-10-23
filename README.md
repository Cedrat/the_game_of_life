# the_game_of_life

This program is a simulation following the principle of the Conway's Game of Life.
You did'nt know ?  
Is a  is a cellular automaton, it is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

The principle are simple.
The game play on a grid. Each cells can be empty or lived by a cell.
  
This game is a turn-by-turn.  


000  
0C0  
000  

For see the state of the cells at the next turn, we need to count the cells alive around herself.  
if the cell have exactly 3 alive neighborgs, at the next turn, she will be alive.  
else if the cell have exactly 2 alive neighborgs, at the next turn, she stay in current state.  
else the cell will die next turn.
