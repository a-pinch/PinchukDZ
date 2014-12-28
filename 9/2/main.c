#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m = 0, f =0, start = 1000, vasiaCur = 1000, vasiaCurCent = 0, sashaCur = 1000, sashaCurCent = 0;
    double tmp;
    printf(" ------------------------------------ \n");
    printf("| month |  Sasha  |  Vasia  |  diff  |\n");
    printf(" ------------------------------------ \n");
    printf("| %3d   | %7.2f | %7.2f |\n", m, sashaCur + (double)sashaCurCent / 100, vasiaCur + (double)vasiaCurCent / 100);
    do{
        m += 3;
        tmp = (double)start / 100 * 6 / 12 * 3;
        sashaCurCent += round((tmp - trunc(tmp)) * 100);
        sashaCur += tmp + sashaCurCent / 100;
        sashaCurCent = sashaCurCent % 100;
        tmp = (vasiaCur + (double)vasiaCurCent / 100) / 100 * 4 / 12 * 3;
        vasiaCurCent += round((tmp - trunc(tmp)) * 100);
        vasiaCur += tmp + vasiaCurCent / 100;
        vasiaCurCent = vasiaCurCent % 100;
        printf("| %3d   | %7.2f | %7.2f | %6.2f |\n", m, sashaCur + (double)sashaCurCent / 100, vasiaCur + (double)vasiaCurCent / 100, sashaCur + (double)sashaCurCent / 100 - (vasiaCur + (double)vasiaCurCent / 100));
    }while(sashaCur + (double)sashaCurCent / 100 > vasiaCur + (double)vasiaCurCent / 100 || !f++);
    printf(" ------------------------------------ \n");
    return 0;
}
