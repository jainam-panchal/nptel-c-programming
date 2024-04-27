#include <stdio.h>
#define MAXSIZE 20

int findCommonSmallest(int *arr1, int size1, int *arr2, int size2)
{
    int smallest = -1;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (smallest == -1 || arr1[i] < smallest)
                {
                    smallest = arr1[i];
                }
            }
        }
    }

    return smallest;
}

int main()
{
    int size1, size2, ans;
    int arr1[MAXSIZE], arr2[MAXSIZE];

    // get arr1
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    // get arr2
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    ans = findCommonSmallest(arr1, size1, arr2, size2);
    printf("%d", ans);

    return 0;
}