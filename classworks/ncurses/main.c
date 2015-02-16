#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 199309

#include <sys/ioctl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h>

void treatSigWinch(int signo);
void initializeProgram();
enum Colors{normal, green, red};

int main(){
    initializeProgram();
    attron(COLOR_PAIR(green));
    printw("Hello world!\n");
    //attroff(COLOR_PAIR(green));
    refresh();
    getch();
//    attron(A_BLINK|A_BOLD);
    attron(A_BLINK);
    move(0,0);
    printw("Hello wor");
    //attroff(A_BLINK|A_BOLD);
    attroff(A_BLINK);
    attroff(COLOR_PAIR(green));
    refresh();
    getch();
    endwin();
    return 0;
}

void initializeProgram(){
    setlocale(LC_ALL, "");
    initscr();
    signal(SIGWINCH, treatSigWinch);
    if(has_colors() == FALSE){
        endwin();
        fprintf(stderr, "no colors\n");
        exit(1);
    }
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    //init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(normal, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
}

void treatSigWinch(int signo){
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char*) &size);
    resizeterm(size.ws_row, size.ws_col);
}
