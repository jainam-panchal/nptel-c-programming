#include <stdio.h>
#include <stdlib.h>

void printPath(int *arr, int i , int j, int n, int current, char *ans) {
    if(i == n-1 && j == n-1) {
        ans[current] = '\0';
        printf("%s" , ans);
        return;
    }

    // go right
    if(j + 1 < n && arr[i * n + (j+1)] == 1) {
        ans[current] = 'R';
        printPath(arr , i , j+1 , n , current+1 , ans);
    }


    // go down
    if(i + 1 < n && arr[(i+1) * n + j] == 1) {
        ans[current] = 'D';
        printPath(arr, i+1 , j, n , current+1 , ans);
    }

}

int main() {
    int n, i, j;
    scanf("%d" , &n);

    int *arr = malloc((n*n) * sizeof(int));
    for(i=0 ; i<n ; i++) {
        for(j=0 ; j<n ; j++) {
            scanf("%d" , &arr[i*n + j]);
        }
    }

    char string[n*n];
    printPath(arr, 0, 0 , n ,0, string);

    free(arr);
    return 0;

}