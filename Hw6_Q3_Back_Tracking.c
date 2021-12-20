#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Final homework in C language TCSD 14
//student: Yiftach Navot
// Hw 6 Q 3 backtracking soduko
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/// this function makes the board for the first time ////////////////////////////////////////////////
int board_maker (int N, int board [N][N])
{
    for (int row = 0; row<N; row++)
    {
        for (int column = 0; column<N; column++)
        {
            board [row][column] = 0;
        }
    }
    return **board;
}

/// this function prints the current board //////////////////////////////////////////////////////
void board_printer (int N, int board [N][N])
{
    for (int row = 0; row<N; row++)
    {
        for (int column = 0; column<N; column++)
        {
            printf ("%d", board [row][column]);
        }
        printf ("\n");
    }
    printf ("\n\n");
}

/// this function builds the board ////////////////////////////////////////////////////////////
int board_builder (int N, int board [N][N])
{
    int row = 0;
    int column = 0;
    printf ("now its time to set your board!\nplease type a row and column to mark them with a number\n");
    printf ("when your done just type in 0\n");

    do
    {
        printf ("row: \n");
        scanf ("%d", &row);

        if (row > N || row < 0)
        {
            printf ("invalid input!\n");
            continue;
        }

        if (row == 0)
        {
            printf ("your final board is: \n");
            board_printer (N, board);
            return **board;
        }

        printf ("column: \n");
        scanf ("%d", &column);

        if (column > N || column < 0)
        {
            printf ("invalid input!\n");
            continue;
        }

        if (column == 0)
        {
            printf ("your final board is: \n");
            board_printer (N, board);
            return **board;
        }

        if (board [row-1][column-1] != 0)
        {
            printf ("you already marked that spot! pick another!\n");
            continue;
        }

        printf ("number to place: \n");
        scanf ("%d", &board [row-1][column-1]);

        if (board [row-1][column-1] > N || board [row-1][column-1] < 0)
        {
            board [row-1][column-1] = 0;
            printf ("invalid input!\n");
            continue;
        }

        board_printer (N, board);
    }
    while (row != 0 || column != 0);

    return **board;
}

/// this function initializes used array to 0 ////////////////////////////////////////////
int used_initilazing (int N, int used [N])
{

    for (int index = 0; index<N; index++)
    {
        used [index] = 0;
    }

    return used[N];
}

/// this function checks if the board is solvable //////////////////////////////////////////////////////////////
bool is_solvable (int N, int board[N][N])
{
    int used [N];

    // checking for solvability in rows
    for (int row = 0; row<N; row++)
    {
        used_initilazing (N, used); // initializing the used array between the rows ////

        for (int column = 0; column<N; column++)
        {
            if (board [row][column] != 0)
            {
                if (used[board [row][column]-1] == 1 || board [row][column] > N || board [row][column] < 0)
                {
                    return false;
                }
                used [board [row][column]-1] = 1;
            }
        }
    }

    // checking for solvability in columns
    for (int column = 0; column<N; column++)
    {
        used_initilazing (N, used); // initializing the used array between the columns ////

        for (int row = 0; row<N; row++)
        {
            if (board [row][column] != 0)
            {
                if (used[board [row][column]-1] == 1)
                {
                    return false;
                }
                used [board [row][column]-1] = 1;
            }
        }
    }

    return true;
}

/// this function checks if a number is safe to place at the current cell //////////////////////////////////////////////////
bool is_safe (int N, int board [N][N], int row, int column, int number)
{
    // checking the row ////
    for (int index = 0; index <N; index++)
    {
        if (board[row][index] == number)
        {
            return false;
        }
    }

    // checking the column ////
    for (int index = 0; index <N; index++)
    {
        if (board[index][column] == number)
        {
            return false;
        }
    }

return true;
}

/// this function is solving the board //////////////////////////////////////////////////////////////////
bool board_solver (int N, int board [N][N], int row, int column)
{
    //board_printer (N, board);

    if (row == N-1 && column == N && is_solvable (N, board)) // stopping condition ////
    {
        printf ("your solved board is:\n");
        board_printer (N, board);
        return true;
    }

    if (column == N) // moving to next row ////
    {
        row++;
        column = 0;
    }
    if (board[row][column] != 0) // if the current cell is not empty ////
    {
        return board_solver(N, board, row, column + 1);
    }

    for (int number = 1; number <= N; number++) // the numbers to place at the current cell ////
    {
        if (is_safe (N, board, row, column, number)) // checking if a number is safe to place at the current cell ////
        {
            board [row][column] = number;

            if (board_solver (N, board, row, column+1))
            {
                return true;
            }
        }

        board [row][column] = 0; // initializing the cell  back to 0 in case of return //////////
    }

return false;
}

int main()
{
int N = 0;
int row = 0;
int column = 0;
printf ("backtracking\n");
printf ("--------------------------\n");

printf ("please enter a board size: "); // comment is case of check
scanf ("%d", &N); // comment is case of check

/// place soduko to check here ///////////

int board [N][N]; /* = {
                       {7,1,0,0,0,0,6,0,0},
                       {2,0,0,0,0,3,0,0,0},
                       {0,0,0,1,5,0,0,0,8},
                       {0,0,7,0,0,0,0,9,0},
                       {0,0,6,0,0,0,7,0,0},
                       {0,2,0,0,0,0,4,0,0},
                       {1,0,0,0,2,9,0,0,0},
                       {0,0,0,3,0,0,0,0,4},
                       {9,0,5,0,0,0,0,8,6}
                       }; */

board_maker (N, board); // comment is case of check
board_printer (N, board);
board_builder (N, board); // comment is case of check

if (!is_solvable (N, board))
{
    printf ("there is no solution!");
    return false;
}

if (!board_solver (N, board, row, column))
{
    printf ("there is no solution!");
    return false;
}

    return 0;
}
