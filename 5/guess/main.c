#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x, i;
    char a;
    do{
        i = 0;
        n = 1+rand()%99;
        printf("I make a number. Try to guess: ");
        do{
            scanf("%d", &x);
            i++;
            if(x<n){
                printf("more \n");
            }else if(x>n){
                printf("less \n");
            }
        }while(x!=n);
        printf("Bingo! %d attempts", i);
        do{
            printf("Continue (y/n) ");
            scanf(" %c", &a);
        }while(a != 'y' && a != 'n');
    }while(a == 'y');
    return 0;
}
