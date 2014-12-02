#include <stdio.h>
#include <stdlib.h>

int main()
{
    char m[] = "mama", l[] = "mila", r[] = "ramu";
    printf("%s %s %s\n", m,l,r);
    printf("%s %s %s\n", m,r,l);
    printf("%s %s %s\n", l,m,r);
    printf("%s %s %s\n", l,r,m);
    printf("%s %s %s\n", r,l,m);
    printf("%s %s %s\n", r,m,l);
    return 0;
}
