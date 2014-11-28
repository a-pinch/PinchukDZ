#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int r,h,l;
    printf("Input radius and height of a cone:\n");
    scanf("%d%d",&r,&h);
    printf("Volume of the cone: %.3f\n", (1.0/3)*M_PI*r*r*h);
    l = sqrt(pow(r,2) + pow(h,2));
    printf("Total surface: %.3f\n", M_PI*r*(r+l));
    return 0;
}
