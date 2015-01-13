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
    if(p<0){
        printf("%d ^ %d = %.5f",a,p,binpow(a,p));
    }else{
        printf("%d ^ %d = %.0f",a,p,binpow(a,p));
    }
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
