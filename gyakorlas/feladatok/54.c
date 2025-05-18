#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        int x = 1;
        fprintf(stderr, "Child...  x=%d (PID=%d, parent is %d)\n", x, getpid(), getppid());

        int sum = 0;
        for (int i = 0; i < getpid(); i++)
        {
            sum += i;
        }

        printf("%d\n", sum);
    }
    else
    {
        int x = 2;
        fprintf(stderr, "Parent...  x=%d (PID=%d, parent is %d)\n", x, getpid(), getppid());

        int sum = 0;
        for (int i = 0; i < getpid(); i++)
        {
            sum += i;
        }

        printf("%d\n", sum);
    }
    return 0;
}