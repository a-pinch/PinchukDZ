#include <stdio.h>
#include <stdlib.h>

typedef struct Anything_ {
    int x;
    struct Anything_ *s;
} Anything;

int main()
{
    Anything a, b;
    a = b;
    b = a;
    printf("Hello world!\n");
    return 0;
}
