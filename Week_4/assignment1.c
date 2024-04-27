#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float mean;
    int result = 0;
    long long total = 0;

    // to store elements
    int i;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    // getting the input
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i];
    }

    // calculating the mean
    mean = (float)total / n;

    // count elements greater than mean
    for (i = 0; i < n; i++)
    {
        if (arr[i] >= mean)
            result += arr[i];
    }

    free(arr);
    printf("%d", result);
}