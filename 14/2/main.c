#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/mymath.h"

int main()
{
    int a, n;
    char buff[256];
    printf("Input number: ");
    scanf("%d", &a);
    printf("Input radix: ");
    scanf("%d", &n);
    printf("%d in radix %d = %s",a,n, _10tor(a,n,buff));
    return 0;
}
