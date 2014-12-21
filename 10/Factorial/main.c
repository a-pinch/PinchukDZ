#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,f=1;
    printf("Input a number: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        f*=i;
    }
    printf("%d! = %d",n,f);
    return 0;
}
