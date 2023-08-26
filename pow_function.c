#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

double myPow(double x, int n)
{
    unsigned long long i = (n);
    double result = 1.0;
    if (n < 0)
        i = -1 * i;
    while (i)
    {
        if (i % 2 == 1)
        {
            result *= x;
        }
        x = x * x;
        i = i / 2;
    }

    if (n < 0)
        return 1 / result;
    return result;
}

int main()
{
    double x=23;
    int n=4;
    printf("%f\n",myPow(x,n));
    return 0;
}