#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
*/

// send array int **
//  FOBS in grid
// s=c-s
// int sum=0;
// return (sum+=s);

struct node
{
    int data;
    struct node *next;
};

void print(int **arr, int r, int c)
{
    printf("%d %d\n", r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}



int countneg(int **arr, int r, int c)
{
    int ci = 0;
    int sum = 0;
    int ri = r - 1;
    while (ri >= 0 && ci < c)
    {

        if (arr[ri][ci] < 0)
        {
            ri--;
            sum = sum + (c - ci);
        }
        else
        {
            ci++;
        }
    }

    return sum;
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int **arr = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // printf("\n");
    printf("%d\n", countneg(arr, r, c));

    // print(arr, r, c);

    // deallocate memory
    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}