// Find moving average
#include <stdio.h>
int main()
{

    int first, second;
    int data = 0;
    float result;
    scanf("%d %d", &first, &second);
    result = ((float)first + (float)second) / 2.0;
    printf("%.1f", result);

    while (data != -1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        printf(" ");
        first = second;
        second = data;
        result = ((float)first + (float)second) / 2.0;
        printf("%.1f", result);
    }

    return 0;
}