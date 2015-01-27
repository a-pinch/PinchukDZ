#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/mymath.h"

int main()
{
    int s, arr[256];
    printf("Input array size (less then 256): ");
    scanf("%d", &s);
    for(int i=0; i<s; ++i){
        arr[i] = myRandom();
    }
    printf("Random array: ");
    displayArrayInt(arr, s);
    printf("\n max=%d min=%d\n", maxInt(arr,s), minInt(arr,s));
    return 0;
}
