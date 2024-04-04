#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sudoku.h"

//implementations of the functions in "sudoky.h"
void print_sudoku(int sudoku[9][9])
{
    printf("x-------x-------x-------x\n");
    for (int j = 0; j < 9; j++)
    {
        printf("| ");
        for (int i = 0; i < 9; i++)
        {
            printf("%d ", sudoku[j][i]);
            if (i % 3 == 2)
                printf("| ");
        }
        printf("\n");
        if (j % 3 == 2)
            printf("x-------x-------x-------x\n");
    }
    printf("\n");
}

void write_sudoku(FILE *file, int sudoku[9][9])
{
    fprintf(file, "Printed Sudoku Grid: \n");
    fprintf(file, "x-------x-------x-------x\n");
    for (int j = 0; j < 9; j++)
    {
        fprintf(file, "| ");
        for (int i = 0; i < 9; i++)
        {
            fprintf(file, "%d ", sudoku[j][i]);
            if (i % 3 == 2)
                fprintf(file, "| ");
        }
        fprintf(file, "\n");
        if (j % 3 == 2)
            fprintf(file, "x-------x-------x-------x\n");
    }
}

int is_valid_sudoku(int sudoku[9][9])
{
    // check rows/columns
    for (int i = 0; i < 9; i++)
    {
        int rows[10] = {0};
        int columns[10] = {0};
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] != 0 && rows[sudoku[i][j]] == 1)
                return 0;
            if (sudoku[j][i] != 0 && columns[sudoku[j][i]] == 1)
                return 0;
            rows[sudoku[i][j]]++;
            columns[sudoku[j][i]]++;
        }
    }

    // check boxes
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            // this will check each top-left corner of each box
            int box[10] = {0};
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (sudoku[i + k][j + l] != 0 && box[sudoku[i + k][j + l]] == 1)
                        return 0;
                    box[sudoku[i + k][j + l]]++;
                }
            }
        }
    }
    // if its passes previous test cases
    return 1;
}

int is_valid_move(int sudoku[9][9], int row, int column, int value)
{
    // check row
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == value)
        {
            return 0; // Invalid move
        }
    }

    // check column
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][column] == value)
        {
            return 0; // Invalid move
        }
    }

    // check box, starting at top-left corner
    int start_row = (row / 3) * 3;
    int start_col = (column / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (sudoku[i][j] == value)
            {
                return 0; // Invalid move
            }
        }
    }
    return 1;
}

int generate_truly_random_sudoku(int sudoku[9][9], int difficulty)
{
    if (difficulty < 0 || difficulty > 81)
        return 0;

    // initialize the empty sudoku
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            sudoku[i][j] = 0;
    }

    srand(time(NULL));
    int filled = 0;
    while (filled < difficulty)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        int value = rand() % 9 + 1;

        if (sudoku[row][col] == 0 && is_valid_move(sudoku, row, col, value))
        {
            sudoku[row][col] = value;
            filled++;
        }
    }
    return 1;
}

int check_solved(int sudoku[9][9], int *row, int *column)
{
    for (*row = 0; *row < 9; (*row)++)
    {
        for (*column = 0; *column < 9; (*column)++)
        {
            if (sudoku[*row][*column] == 0)
                return 0;
        }
    }
    return 1;
}

int solve_sudoku(int sudoku[9][9])
{
    /*BASE CASE - already solved (check_solved() == 1)
    - find next empty spot
    - use numbers 1-9 to fill position
    - check if the new sudoku is valid
        - if its not, make the spot 0 again and try again
        - if it is:
            - RECURSIVE CASE:
            - call solve_sudoku again with modified input
    */
    if (!is_valid_sudoku(sudoku))
    {
        //printf("Not a valid sudoku\n");
        return 0;
    }

    int row, column;
    // find the next empty spot using check_solved
    if (check_solved(sudoku, &row, &column) == 0)
    {
        for (int i = 1; i < 10; i++)
        {
            if (is_valid_move(sudoku, row, column, i))
            {
                sudoku[row][column] = i;

                // recursively try to solve the sudoky
                if (solve_sudoku(sudoku))
                    return 1;

                // if sudoku cannot be solved with number, backtrack and try again
                sudoku[row][column] = 0;
            }
        }
        return 0; // there is no valid sudoku
    }
    return 1; // already solved
}
