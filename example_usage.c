#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sudoku.h"

int main()
{
    int sudoku_grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    // this function is currently under development
    // generate_truly_random_sudoku(sudoku_grid, 20);

    printf("Input sudoku grid:\n");
    print_sudoku(sudoku_grid);

    int solvable = solve_sudoku(sudoku_grid);

    if (solvable)
    {
        printf("Solution printed and written to 'sudoku.txt'\n\n");
        FILE *file = fopen("sudoku.txt", "w");
        print_sudoku(sudoku_grid);
        write_sudoku(file, sudoku_grid);
        fclose(file);
    }
    else
        printf("Sudoku is unsolvable, program ended\n");

    return 0;
}
