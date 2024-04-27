// Write a C program to count the number of 0's between the first and last 1 in the sequence.

#include <stdio.h>
int main()
{
    int data = 0;
    int flag = 0;

    int count = 0;
    int result = 0;

    while (data != -1)
    {
        scanf("%d", &data);

        // open the flag
        if (flag == 0 && (data == 1))
        {
            flag = 1;
        }

        // inc the counter
        else if (flag == 1 && (data == 0))
        {
            count++;
        }

        // close the flag
        else if (flag == 1 && data == 1)
        {
            flag = 0;
            result += count;
            count = 0;
        }
    }

    printf("%d", result);
    return 0;
}