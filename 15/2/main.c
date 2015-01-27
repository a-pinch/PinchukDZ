#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/mymath.h"

#define ARRAY_SIZE 10

int main()
{
    int i, n, arr[ARRAY_SIZE];
    printf("Input %d numbers: ",ARRAY_SIZE);
    for(int i=0; i<ARRAY_SIZE; ++i){
        scanf("%d", &arr[i]);
    }
    printf("You input an array:\n");
    displayArrayInt(arr, ARRAY_SIZE);
    printf("\n Input number: ");
    scanf("%d", &n);
    i = indexOfInt(n, arr, ARRAY_SIZE);
    if(i<0){
        printf("%d is not in the array", n);
    }else{
        printf("index of %d in the array is %d", n, i);
    }
    return 0;
}
