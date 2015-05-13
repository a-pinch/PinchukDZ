#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>  //многопроцессорность
#include <sys/types.h>
#include <signal.h>
#include <wait.h>

#define TIME 5000

int read_file = 1;

void sig_handler(int snum)
{
    read_file = 0;
}


int main()
{
    //канал связи
    int pf[2];
    if(pipe(pf) == -1)
    {
        fprintf (stderr, "pipe() error\n");
        return 1;
    }

    //исходный процесс
    pid_t p = fork();
    if(p == -1)
    {
        fprintf(stderr, "Error, fork don't created!\n");
        return 1;
    }
    else if(p == 0)
    {
        //сын
        pid_t p1 = fork();
        if(p1 == -1)
        {
            fprintf(stderr, "Error, fork don't created!\n");
            return 1;
        }
        else if(p1 == 0)//внук
        {
            //обработка сигнала
            struct sigaction act;
            sigemptyset(&act.sa_mask);
            act.sa_handler = &sig_handler;
            act.sa_flags = 0;
            if(sigaction (SIGQUIT, &act, NULL) == -1)
            {
                fprintf (stderr, "sigaction() error\n");
                return 1;
            }

            FILE *file;
            char symbol;
            fopen("test.txt", "r");

            while(read_file && !feof(file))
            {
                symbol = fgetc(file);
                write(pf[0], &symbol, sizeof(char));
            }
            symbol = '\0';
            write(pf[0], &symbol, sizeof(char));


            fclose(file);
            close(pf[0]);        }
        else//обработка p1
        {
            sleep(TIME);
            kill(p1, SIGQUIT);
        }
    }
    else
    {
        wait(NULL);
        char symbol;

        do
        {
            read(pf[1], &symbol, sizeof(char));
            printf("%c", symbol);
        }while(symbol != '\0');
    }





    return 0;
}
