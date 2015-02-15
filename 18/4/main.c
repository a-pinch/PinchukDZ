#include <stdio.h>
#include <stdlib.h>
#include "../../modules/includes/compatibility.h"

void displaySymbol(int s){
    switch(s){
    case 0:
        printf(" ");
        break;
    case 1:
        printf("X");
        break;
    case 2:
        printf("O");
        break;
    default:
        printf("?");
    }
}

void displayPole(int pole[][3], int im, int jm){
    universalClear();
    printf("\n");
    for(int i=0; i<im; ++i){
        if( i!= 0){
            for(int j=0; j<jm; ++j){
                printf("----");
            }
            printf("\n");
        }
        for(int j=0; j<jm; ++j){
            if(j != 0 ){
                printf(" | ");
            }else{
                printf(" ");
            }
            displaySymbol(pole[i][j]);
        }
        printf("\n");
    }
}

int getIntStep(char x){
    return x - 64;
}

int findEmpty(int pole[][3], int im, int jm){
    for(int i=0; i<im; ++i){
        for(int j=0; j<jm; ++j){
            if(pole[i][j] == 0) return 1;
        }
    }
    return 0;
}

int getEmptyCount(int pole[][3], int im, int jm){
    int c=0;
    for(int i=0; i<im; ++i){
        for(int j=0; j<jm; ++j){
            if(pole[i][j] == 0) ++c;
        }
    }
    return c;
}

void makeComputerStep(int pole[][3], int im, int jm){
    int c = getEmptyCount(pole, im, jm);
    int r = rand()%c;
    for(int i=0; i<im; ++i){
        for(int j=0; j<jm; ++j){
            if(pole[i][j] == 0){
                if(r==0) {
                    pole[i][j] = 2;
                    return;
                }
                else --r;
            }
        }
    }
}

void makeHumanStep(int pole[][3]){
    int xi, yi, f;
    char x;
    do{
        f=0;
        printf("Input you step (for exaqmple A1) or 'q' for quit: ");
        scanf("%c", &x);
        if(x == 'q'){
            return 0;
        }
        scanf("%d",&yi);
        xi = getIntStep(x);
        if(xi>0 && xi<=3 && yi>0 && yi<=3){
            pole[xi-1][yi-1] = 1;
            f=1;
        }else{
            printf("wrong input\n");
        }
    }while(!f);
}

void checkWin(int pole[][3], int im, int jm){
    int w = 0;
    for(int i=0; i<im; ++i){
        w = checkWinRow(i, pole, im, jm);
        if(w != 0) break;
    }
    if( w == 0){
        for(int j=0; j<jm; ++j){
            w = checkWinCol(j, pole, im, jm);
            if(w != 0) break;
        }
    }
    if( w == 0) w = checkWinDiagonal(0,0);
    if(w == 0) w = checkWinDiagonalReverce(0,3, pole, 3, 3);
    switch(w){
        case 1:
            printf("You win! Congratulation!!!\n");
            return 0;
        case 2:
            printf("Computer win! Sorry...\n");
            return 0;
    }
    return;
}

int checkWinRow(int row, int pole[][3], int im, int jm){
    int c = pole[row][0];
    for(int i=1; i<im; ++i){
        if(pole[row][i] != c) return 0;
    }
    return c;
}

int checkWinCol(int col, int pole[][3], int im, int jm){
    int c = pole[0][col];
    for(int i=1; i<im; ++i){
        if(pole[i][col] != c) return 0;
    }
    return c;
}

int checkWinDiagonal(int row, int col, int pole[][3], int im, int jm){
    int c = pole[row][col];
    for(int i=row+1, j=col+1; i<im, j<jm; ++i, ++j){
        if(pole[i][j] != c) return 0;
    }
    return c;
}

int checkWinDiagonalReverce(int row, int col, int pole[][3], int im, int jm){
    int c = pole[row][col];
    for(int i=row+1, j=col-1; i<im, j>=0; ++i, --j){
        if(pole[i][j] != c) return 0;
    }
    return c;
}

int main()
{
    int pole[3][3]={0,0,0,0,0,0,0,0,0};
    int comp = 0;
    displayPole(pole,3,3);
    while(findEmpty(pole,3,3)){
        if(comp){
            makeComputerStep(pole, 3, 3);
        }else{
            makeHumanStep(pole);
        }
        displayPole(pole, 3, 3);
        comp = !comp;
        checkWin(pole, 3, 3);
    }
    printf("finish");
    return 0;
}
