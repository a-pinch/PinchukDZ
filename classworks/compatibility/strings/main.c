#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str1 = "mamarama";
    char str2[9]="mamarama";
    str2[0] = 'r';
    printf("%s\t%s\n",str1,str2);
    return 0;
}
