#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Prints a given sudoku, in an easy-to-read format, best
 * for visualization
 * @param sudoku The 9x9 sudoku grid that is printed
 */
void print_sudoku(int sudoku[9][9]);

/**
 * Writes a given sudoku, in an easy-to-read
 * format into a file named sudoku.txt
 * @param file The file stream to write to
 * @param sudoku The 9x9 sudoku grid written to a file
 */
void write_sudoku(FILE *file, int sudoku[9][9]);

/**
 * Function to check whether the inputted sudoku grid is valid,
 * ie: has 1-9 in each box, column, row. Incomplete sudoku grids
 * are still valid, where empty cells are left at 0.
 * @param sudoku The 9x9 Sudoku grid to be checked
 * @return 1 if the sudoku is valid, 0 if not
 */
int is_valid_sudoku(int sudoku[9][9]);

/**
 * Function to check whether a specific move is valid in the sudoku
 * @param sudoku The 9x9 sudoku grid to be checked
 * @param row The row where the move is to be placed
 * @param column The column where the move is to be placed
 * @param value The value going into the cell at sudoku[row][column]
 * @return 1 if the move is valid, 0 if not
 */
int is_valid_move(int sudoku[9][9], int row, int column, int value);

/**
 * Function that randomly generates a valid sudoku
 * This method of random generation is truly random, meaning it is
 * randomly picks numbers for each cell. As this type of randomness has
 * a large time complexity it is recommended to input difficulty levels
 * between (0-65). Any higher will cause the program to behave very slowly.
 * @param sudoku Any 9x9 sudoku grid to write the generated sudoku to
 * @param difficulty The number of cells that you wish the sudoku to have
 * @return 1 if the sudoku is generated, 0 if difficulty is invalid
 * @note EXPERIMENTAL: THERE MAY BE ISSUES WITH THIS FUNCTION
 */
int generate_truly_random_sudoku(int sudoku[9][9], int difficulty);

/**
 * Function that finds the next empty cell in the grid
 * @param sudoku The 9x9 sudoku grid to be checked
 * @return 1 if the sudoku is already solved, 0 if not
 */
int check_solved(int sudoku[9][9], int *row, int *column);

/**
 * Function that recursively tries to solve the sudoku.
 * Calls other functions listed above, and modifies the input
 * grid to be solved. Note that empty cells are marked with 0
 * @param sudoku The 9x9 sudoku grid to be solved
 * @return 1 if the sudoku was solved correctly, 0 if it
 * was not solved/it was unsolvable
 */
int solve_sudoku(int sudoku[9][9]);

#endif /* SUDOKU_H */
