#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Input number: ");
    scanf("%d",&n);
    for(int i=2;i<=n/2;i++){
        if(n%i == 0){
            printf("%d isn't a simple number", n);
            return 0;
        }
    }
    printf("%d is a simple number", n);
    return 0;
}
