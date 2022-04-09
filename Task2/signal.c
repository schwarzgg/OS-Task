#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>

int f = 1;

void make_stop() {
    f = 0;
    return ;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    pid_t pid1,pid2;

    f = 1;
    signal(2,make_stop);
    while (f == 1) {}

    pid1 = fork();

    if (pid1 > 0)
    {
        pid2 = fork();

        if (pid2 > 0)
        {
            f = 1;
            usleep(50);
            kill(pid1,16);
            kill(pid2,17);
            wait(0);

            printf("Parent killed\n");
            exit(0);
        }
        else
        {
            f = 1;
            signal(17,make_stop);
            while (f == 1) {}
            printf("PID2 : Child ID:%d killed\n",getpid());
            exit(0);
        }

    }
    else 
    {
        f = 1;
        signal(16,make_stop);
        while (f == 1) {}
        printf("PID1 : Child ID:%d killed\n",getpid());
        exit(0);
    }
}
