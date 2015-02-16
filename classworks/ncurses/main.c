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

int main(){
    initializeProgram();
    attron(COLOR_PAIR(1));
    printw("Hello world");
    attroff(COLOR_PAIR(1));
    refresh();
    getch();
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
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

void treatSigWinch(int signo){
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char*) &size);
    resizeterm(size.ws_row, size.ws_col);
}
