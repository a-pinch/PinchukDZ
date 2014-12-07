#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    printf("Input number: ");
    scanf("%d",&c);
    for(int i=1; i<=c; i++){
        printf("%d ",i);
    }
    return 0;
}
