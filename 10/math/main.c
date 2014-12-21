#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, eps=1e-3, res, ad;
    int i;
    printf(" -----------------------------------\n");
    printf("|   x   |   my  |  math |    diff   |\n");
    printf(" -----------------------------------\n");
    for(x=-2;x<=2;x+=0.1){
        res = 0; ad = 1; i = 0;
        while(fabs(ad) > eps){
            res += ad;
            ad *= x / ++i;
        }
        printf("| %5.2f | %5.3f | %5.3f | %9.7f |\n", x, res, exp(x), fabs(res - exp(x)));
    }
    printf(" -----------------------------------\n");
    return 0;
}
