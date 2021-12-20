#include <stdio.h>
#include <stdbool.h>

//Final homework in C language TCSD 14
//student: Yiftach Navot
// Hw 6 Q 1 Sorting matrix
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// this function makes the matrix for the first time //////////////////////////
int matrix_maker (int n, int matrix [][n])
{
    int row,column;
    for (row=0; row<n ; row++)
    {
        for (column=0; column<n ;column++)
        {
            printf ("please enter your next matrix value: ");
            scanf ("%d", &matrix[row][column]);
        }
    }
return 0;
}

/// this function prints a given matrix ///////////////////////////
void matrix_printer (int n, int matrix[][n])
{
    int row,column;
    for (row=0; row<n; row++)
    {
        for (column=0; column<n;column++)
        {
            printf("%d ", matrix[row][column]);
        }
        printf ("\n");
    }
}

/// this function swaps the location of two given numbers ////////////////////////////
int swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

/// this function finds the location of the max value in a given row of an array //////////////////////
int index_of_max (int column_limit, int column_limit_up, int column_limit_down, int n, int row, int matrix [n][n])
{
    int column_max = column_limit;

    for (int column=column_max; column >= column_limit_down && column <= column_limit_up; column) // known warning - updating at end of function
    {
        if (matrix[row][column]>matrix[row][column_max])
        {
            column_max = column;
        }

        if (row % 2 != 0) // if row is odd
        {
            column++;
        }
        else // if row is even
        {
            column--;
        }
    }
    return column_max;
}

/// this function does MAX sort in a given matrix /////////////////////////////////////////////////////////////////////////
int max_sort (int n, int matrix[n][n])
{
    for (int row=0; row<n; row++)
    {
        int column_limit_up = n-1;
        int column_limit_down = 0;
        int column_limit = 0;
        int max_index = n-1;

        if (row % 2 != 0) // if row is odd the max sorting starts from the 0 cell of the line
            {
                column_limit = column_limit_down;
            }
            else // if row is even the max sorting starts from the n-1 cell of the line
            {
                column_limit = column_limit_up;
            }

        for (max_index = column_limit; max_index >=column_limit_down && max_index <= column_limit_up; max_index) // known warning - updating at end of function
        {
            int column_max = index_of_max (column_limit ,column_limit_up, column_limit_down, n, row, matrix); // checking the max index of the row

            if (max_index != column_max)
            {
                swap (&matrix[row][max_index], &matrix[row][column_max]); // swapping between the current max value and the max found if not in place
            }

            if (row % 2 != 0) // if row is odd
            {
                max_index++;
                column_limit++;
            }
            else // if row is even
            {
                max_index--;
                column_limit--;
            }
        }
    }
    return matrix[n][n];
}

int main()
{
printf ("sorting\n");
printf ("---------------------------------\n");
int n = 0;

printf ("please enter a size for your sorting matrix:\n"); // comment is case of check
scanf ("%d", &n); // comment is case of check

/// place matrix to check here ///////////

int matrix [n][n]; /* = {
                       {1,10,6,4,9,8,1,0},
                       {-1,4,-9,72,13,2,-31,92},
                       {8,-9,2,1,32,0,32,92},
                       {1,9,4,9,8,2,3,90},
                       {8,8,8,8,8,8,8,8},
                       {-9,-3,2,-19,84,2,9,0},
                       {-9,2,41,23,1,9,2,31},
                       {7,7,7,7,7,7,7,7}
                       }; */

printf ("your matrix is %d X %d\n\n", n, n);

matrix_maker (n, matrix); // comment is case of check
printf ("your matrix is: \n");
matrix_printer (n, matrix);
printf ("\n");
max_sort (n, matrix);
printf ("your sorted matrix is: \n");
matrix_printer (n, matrix);
    return 0;
}
