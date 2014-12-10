#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f=0,g=1,n;
    printf("Input number: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        f = f + g;
        g = f - g ;
        printf("%d ", f);
    }
    return 0;
}
