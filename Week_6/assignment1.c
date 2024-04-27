#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main() {
    int n;
    int l_window;

    int i, j;
    scanf("%d", &n);
    scanf("%d", &l_window);
    int *arr = malloc((n * n) * sizeof(int));

    // taking user input array
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i * n + j]);
        }
    }

    // calculating ans matrix
    int ans[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int il = MAX(i - l_window, 0);
            int ih = MIN(i + l_window, n - 1);

            int jl = MAX(j - l_window, 0);
            int jh = MIN(j + l_window, n - 1);

            int x, y;
            int sum = 0;
            for (x = il; x <= ih; x++) {
                for (y = jl; y <= jh; y++) {
                    sum += arr[x * n + y];
                }
            }

            ans[i][j] = sum;
        }
    }

    // printing the ans matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    // free the allocated memory
    free(arr);

    return 0;
}
