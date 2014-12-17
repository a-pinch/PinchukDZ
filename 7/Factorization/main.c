#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int x,i=2;
    bool f = true;
    printf("Input number: ");
    scanf("%d",&x);
    printf("%d = ",x);
    while(x>=i){
        if(x%i == 0){
            if(f){
                f = !f;
            }else{
                printf(" * ");
            }
            printf("%d",i);
            x = x/i;
        }else{
            i++;
        }
    }
    return 0;
}
