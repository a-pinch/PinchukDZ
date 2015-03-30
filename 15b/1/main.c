#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1024], s, f;
    do{
        printf("Input array size (up to 1024): ");
        scanf("%d", s);
    }while(s<0 || s>1024);
    do{
        printf("Fill array with random numbers or manualy (1/0)?")
        scanf("%d", f);
    }while(f<0 || f>1);
    if(f){

    }
    return 0;
}
