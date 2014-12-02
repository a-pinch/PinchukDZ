#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[] = "15:07:03";
    int h=3,m=47,s=8;
    printf("%s\n",a);
    printf("%.2d:%.2d:%.2d\n",h,m,s);
    h=23;m=11;s=0;
    printf("%.2d:%.2d:%.2d\n",h,m,s);
    return 0;
}
