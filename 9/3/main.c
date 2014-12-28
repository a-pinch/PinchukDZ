#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,len;
    printf("Input positive number: ");
    scanf("%d",&n);
    if(n<0){
        printf("Error\n");
    }
    if(n<2){
        printf("Number %d is a polindrom.",n);
        return 0;
    }
    len = n==10 ? 2 : (int)ceil(log10(n));
    char N[len];
    sprintf(N, "%d", n);
    for(int i=0; i<len/2;i++){
        if(N[i] != N[len-i-1]){
            printf("Number %d isn't a polindrom.",n);
            return 0;
        }
    }
    printf("Number %d is a polindrom.",n);
    return 0;
}
