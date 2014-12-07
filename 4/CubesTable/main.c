#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf(" -------------- \n");
    printf("| %2c  | %5s  |\n",'x',"x^3");
    printf(" --------------\n");
    for(int i=1; i<=17*2; i+=2){
        printf("| %2d  |  %5d |\n",i,i*i*i);
    }
    printf(" --------------\n");
    return 0;
}
