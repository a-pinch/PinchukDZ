#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main()
{
    char c = getch();
//    noecho();
//	cbreak();
	while(c != 'q'){
        printf("Your turn. Press any key to continue or 'q' to quit.\n");
        c = getch();
	}
    return 0;
}
