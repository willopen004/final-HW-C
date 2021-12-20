#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Final homework in C language TCSD 14
//student: Yiftach Navot
// Hw 6 Q 2 Super factorial
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/// function of paragraph A - head recurtion ////////////////////////////////////////////
int super_factorial1 (int a)
{
    if (a == 1)
    {
        return 1;
    }

    int factor = 1;

    for (int i = a; i>=1; i--) // calculating the inner factorial
    {
        factor *= i;
    }

    return factor*super_factorial1 (a-1);
}

/// function of paragraph B - tail recurtion ////////////////////////////////////////////

int super_factorial2 (int a, int factor, int result)
{
    if (a == 1)
    {
        return result;
    }

    result = result*pow(a, factor); // calculating the inner factorial

    return super_factorial2 (a-1, factor + 1, result);
}

int main()
{
    printf ("super factorial\n");
    printf ("---------------------------------\n");
    int a = 0;
    int b = 0;
    printf ("please enter a number to super factor: \n");
    scanf ("%d", &a);

    printf ("please enter a function number (1 or 2): ");
    scanf ("%d", &b);

    if (b==1)
    {
        printf ("the super factorial of %d is: %d", a, super_factorial1(a));
    }

    if (b==2)
    {
        int factor = 1;
        int result = 1;
        printf ("the super factorial of %d is %d", a, super_factorial2 (a, factor, result));
    }

    return 0;
}
