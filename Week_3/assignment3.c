// Find the kth Odd integer in sequence
#include <stdio.h>
int main()
{
    int k;
    int data = 0;
    int flag = 0;

    scanf("%d", &k);

    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;

        if (!flag && data % 2 == 1)
        {
            k--;
            if (!k)
            {
                printf("%d", data);
                flag = 1;
            }
        }
    }
    return 0;
}