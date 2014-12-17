#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,y=0;
    printf("Input number: ");
    scanf("%d", &n);
    x = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+x; j++){
            printf(" ");
        }
        printf("#");
        printf("\n");
    }
    return 0;
}
