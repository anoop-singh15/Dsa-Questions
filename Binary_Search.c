#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int arr[100];
    int number, n, i, low, mid, high;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

  
    scanf("%d", &number);

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high)
    {
        if (arr[mid] == number)
        {
            printf(" Found at %d", mid + 1);
            break;
        }
        else if (arr[mid] > number)
        {
            high = mid - 1;
        }
        else if (arr[mid] < number)
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;

    }

    if(low>high)
    {
        printf("element Not found\n");
    }
    return 0;
}