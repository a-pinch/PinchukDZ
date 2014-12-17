#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++){
        for(int j=0; j<=n+i; j++){
            if(j == n-i || j == n+i){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    for(i-=2; i>=0; i--){
        for(int j=0; j<=n+i; j++){
            if(j == n-i || j == n+i){
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
