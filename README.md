# Game-Of-Life
This code shows the game of life executed using C. 

The Game Of Life is played on an infinite two-dimensional grid of square cells. Each cell is in one of two possible states - live or dead. Every cell interacts with its eight neighbors that are either horizontally, vertically or diagonally adjacent. At each time step, the following transitions occur:
1. Any live cell with fewer than two live neighbors dies.
2. Any live cell with two or three live neighbors lives on to the next generation. 
3. Any live cell with four or more live neighbors dies.
4. Any dead cell with exactly three live neighbors becomes a live cell.
Note that all births and deaths occur simultaneously. Together, they constitute a single generation.

Note: This version uses an input file as the games initial state. The current version also has a pre-specified number of generations output to the terminal. The terminal output is also color coded for easy readability.
