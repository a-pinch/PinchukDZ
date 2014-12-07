#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,x,p=0,pow=1,pow1=1;
    do{
        printf("Input L (L > 0): ");
        scanf("%d",&l);
    }while(l<=0);
    do{
        printf("Input x (x<=L): ");
        scanf("%d",&x);
    }while(x>l);
    while(pow1<l){
        p++;
        pow = pow1;
        pow1 = 1;
        for(int i=0; i<p; i++){
            pow1 *= x;
        }
    }
    printf("%d^%d = %d",x,--p,pow);
    return 0;
}
