#include <stdio.h>

int oddFunc(int val)
{
    return 3 * val + 1;
}

int evenFunc(int val)
{
    return val / 2;
}

int main()
{
    int input;
    int output;
    int count = 0;

    scanf("%d", &input);

    if (input % 2 == 0)
        output = evenFunc(input);
    else
        output = oddFunc(input);
    count++;

    while (output != 1)
    {
        if (output % 2 == 0)
            output = evenFunc(output);
        else
            output = oddFunc(output);
        count++;
    }

    printf("%d", count);
    return 0;
}