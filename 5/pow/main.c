#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x,p;
    double pow=1;
    printf("Input number: ");
    scanf("%d",&x);
    printf("Input pow:");
    scanf("%d",&p);
    for(int i=0;i<abs(p);i++){
        pow *= x;
    }
    if(p<0) pow = 1.0/pow;
    printf("x^p = %.3f",pow);
    return  0;
}
