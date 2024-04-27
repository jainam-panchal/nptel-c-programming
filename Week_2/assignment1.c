// check for even parity
// 1 if the number of ones in the sequence is even.
// 0 if the number of ones in the sequence is odd.

#include <stdio.h>
int main()
{

    int oneCount = 0;
    int data = 0;

    while(data != -1) {
        scanf("%d", &data);
        if(data == 1)
            oneCount++;
    }

    int result = oneCount%2 == 0 ? 1 : 0;
    printf("%d", result);
    
    return 0;
}