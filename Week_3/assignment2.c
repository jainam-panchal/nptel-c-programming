#include <stdio.h>

int is_prime(int n)
{
    /*
      Complete this function.
      Return 1 if n is prime.
      Return 0 otherwise.
     */

    // not possible
    if (n <= 1)
        return 0;

    // if it's 2 or 3, return true
    if (n == 2 || n == 3)
        return 1;

    // divisible by 2 or 3, return false
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }

    return 1;
}

int main()
{

    int n, num;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (is_prime(num))
        {
            printf("%d ", num);
        }
    }

    return 0;
}