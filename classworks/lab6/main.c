#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>  //многопроцессорность
#include <sys/types.h>
#include <signal.h>

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
        else if(p1 == 0)
        {
            //внук
            pid_t p2 = getpid();
            while(read_file)
            {

            }
        }
        else//обработка p1
        {
            struct sigaction act;
            sigemptyset(&act.sa_mask);
            act.sa_handler = &sig_handler;
            act.sa_flags = 0;

            if (sigaction (SIGINT, &act, NULL) == -1)
            {
                fprintf (stderr, "sigaction() error\n");
                return 1;
            }
        }
    }
    else
    {

    }





    return 0;
}
