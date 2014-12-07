#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, p, pow=1;
    printf("Input x: ");
    scanf("%d",&x);
    printf("Input p: ");
    scanf("%d",&p);
    for(int i=0; i<p; i++){
        pow *= x;
    }
    printf("%d^%d = %d\n", x,p,pow);
    return 0;
}
