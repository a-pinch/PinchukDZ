#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min,max,c,n;
    printf("Input number: ");
    scanf("%d",&n);
    printf("Input %d numbers: ", n);
    for(int i=0;i<n;i++){
        scanf("%d",&c);
        if(i==0){
            min = c;
            max = c;
        }else{
            if(c>max){
                max = c;
            }else if(c<min){
                min = c;
            }
        }
    }
    printf("Max number: %d\n", max);
    printf("Min number: %d\n", min);
    return 0;
}
