#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, p;
    printf("Input namber: ");
    scanf("%d",&c);
    int a[c];
    p = 1;
    printf("Input %d nambers: ", c);
    for(int i=0; i<c; i++){
        scanf("%d", &a[i]);
        p *= a[i];
    }
    for(int i=0; i<c; i++){
        if(i>0) printf("* ");
        printf("%d ", a[i]);
    }
    printf("= %d\n", p);
    return 0;
}
