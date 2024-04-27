// affordable or not

#include <stdio.h>

int main()
{

    int rp100, rp10, rp1, result;
    scanf("%d", &rp100);
    scanf("%d", &rp10);
    scanf("%d", &rp1);
    scanf("%d", &result);

    printf("%d", result == (rp100 * 100) + (rp10 * 10) + rp1);
    return 0;
}