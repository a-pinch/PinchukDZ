#include <stdio.h>
#include <stdlib.h>

double binpow(int a, int p);

int main()
{
    int a,p;
    printf("Input number:");
    scanf("%d",&a);
    printf("Input power:");
    scanf("%d",&p);
    printf("%d ^ %d = %.*f",a,p,p<0?5:0,binpow(a,p));
    return 0;
}

double binpow(int a, int p){
    int res = 1;
    if(p<0) {
        return (double)1/binpow(a,-p);
    }
    while(p){
        if(p & 1){
            res *= a;
        }
        a *= a;
        p >>= 1;
    }
    return res;
}
