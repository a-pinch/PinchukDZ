#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/compatibility.h"

int main()
{
    char c;
    printf("Hello world!\n");
    scanf("%c", &c);
    universalClear();
    return 0;
}
