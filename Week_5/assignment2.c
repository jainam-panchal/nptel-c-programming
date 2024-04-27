#include <stdio.h>
#include <stdlib.h>

int blocksum(int arr[], int start, int end)
{
    if (end - start == 1)
    {
        return arr[start] - arr[end];
    }

    int mid = (start + end) / 2;
    int sumLeft = blocksum(arr, start, mid);
    int sumRight = blocksum(arr, mid + 1, end);

    return sumLeft - sumRight;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
        return 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result = blocksum(arr, 0, n - 1);
    printf("%d", result);
    free(arr);

    return 0;
}