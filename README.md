# Sudoku API

This API provides the core features required to solve and generate Sudoku boards. The main object files, "sudoku.h" and "sudoku.o" are provided.
THe other files include testing files (realsudoku.c combines the API with a program for simple example usage), pre compiled executables, and 
example .txt files for where you can output your Sudoku.


## Using the API

To use the API, there is a provided header file, "sudoku.h" that takes implementations from the corresponding "sudoku.c" file.
The files are already linked and you can use the "sudoku.h" file and the "sudoku.o" file. There is a provided driver file
"example_usage.c" that demonstrates the use of the API. To link the API with your program, use the following command:

```
gcc main.c sudoku.o -o your_title
```
Then simply run 'your_title' with any terminal

## Features

This API provides basic Sudoku features, including:
- Solving a given Sudoku board
- Checking whether a given Sudoku board is solvable
- Printing a Sudoku board
- Writing a Sudoku board to a file
- Generating a random Sudoku board with various levels of difficulty (in Progress)


## Inspiration

Sudoku has always fascinated me, as I remember our teacher demoed a simple Sudoku to teach us back in grade 1. I remember already knowing
how to play the game as my dad had taught me prior, and ever since I have been fascinated by it. This API provides a recursive approach
to many of the problems, and its implementation was done holistically. 

There will be future updates regarding this API, so stay tuned!
