#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/mymath.h"

int main()
{
    int n;
    printf("Input number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(gcd(i,j) = 1){
                printf("#");
            } else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
