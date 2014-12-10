#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<128;i++){
        printf("%2c %3d  ",i++);
        if(i%16 == 15) {
            printf("\n");
        }
    }
    return 0;
}
