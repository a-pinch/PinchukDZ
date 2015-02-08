#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/sipletron.h"
#define DEBUG_MODE 0

int main()
{
    printf("Input a programm: \n");
    simpletron_load(DEBUG_MODE);
    printf("Input programm is finished. \n");
    if(DEBUG_MODE == 1) simpletron_print();
    printf("Execute programm start!\n");
    simpletron_run(DEBUG_MODE);
    printf("\nThe program is finished!\n");
    return(0);
}
