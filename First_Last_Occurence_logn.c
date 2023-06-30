#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Find First and last Occurence of an element in an sorted array

int first_last(int *arr, int first, int last, int search, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int result = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            if(last==-1)
            {
                 high = mid - 1;
            }
            if(first==-1)
            {
                low = mid + 1;
            }          
            result = mid;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n, search;
    // int result2 = -1;
    int *arr = (int *)malloc(100 * sizeof(int));
    int brr[2];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d",&search);

    brr[0] = first_last(arr,1,-1,search,n);
    brr[1] = first_last(arr,-1,1,search,n);

    printf("%d %d\n", brr[0], brr[1]);

    return 0;
}