#include <stdio.h>
#include <stdlib.h>

int isAnagram(char *str1, char *str2, int n)
{
    int result = 1;

    // Initialize the map
    int map1[26];
    int map2[26];
    for (int i = 0; i < 26; i++)
    {
        map1[i] = 0;
        map2[i] = 0;
    }

    // Count all characters
    for (int i = 0; i < n; i++)
    {
        int curr1 = str1[i] - 'A';
        map1[curr1]++;

        int curr2 = str2[i] - 'A';
        map2[curr2]++;
    }

    // Check for anagram
    for (int i = 0; i < 26; i++)
    {
        if (map1[i] != map2[i])
        {
            result = 0;
            break;
        }
    }

    return result;
}

int main()
{
    int n, ans;
    char *str1;
    char *str2;

    scanf("%d", &n);
    str1 = (char *)malloc(n * sizeof(char));
    str2 = (char *)malloc(n * sizeof(char));

    for (int i = 0; i < n; i++)
        scanf(" %c", &str1[i]);

    for (int i = 0; i < n; i++)
        scanf(" %c", &str2[i]);

    ans = isAnagram(str1, str2, n);

    printf("%d", ans);
    return 0;
}