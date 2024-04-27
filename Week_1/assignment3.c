// solve 2x2 linear equation system

#include <stdio.h>
int main()
{

    int a1, b1, c1;
    int a2, b2, c2;
    int del, delx, dely, ansX, ansY;

    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);

    // using cramer's rule
    del = (a1 * b2 - a2 * b1);
    delx = (c1 * b2 - c2 * b1);
    dely = (a1 * c2 - a2 * c1);

    ansX = delx / del;
    ansY = dely / del;

    printf("%d %d", ansX, ansY);

    return 0;
}