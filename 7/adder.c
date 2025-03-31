#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int sum = 0;
int count = 0;
int pipe_fd[2];

void AlarmHandler(int sig)
{
    printf("\nAlarm! TIme is up. Read %d numbers with the sum of %d.\n", count, sum);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    exit(0);
}

int main(int argc, char *argv[])
{
    pid_t pid;
    int num;
    int time = 30;

    if (argc == 2)
    {
        time = atoi(argv[1]);
    }

    if (pipe(pipe_fd) == -1)
    {
        fprintf(stderr, "Error creating pipe.\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "Error forking process.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        printf("Enter integers:\n");
        while (1)
        {
            scanf("%d", &num);
            write(pipe_fd[1], &num, sizeof(int));
        }
        close(pipe_fd[1]);
    }
    else
    {
        signal(SIGALRM, AlarmHandler);
        signal(SIGINT, AlarmHandler);
        alarm(time);

        while (1)
        {
            if (read(pipe_fd[0], &num, sizeof(int) > 0))
            {
                sum += num;
                count++;
            }
        }

        close(pipe_fd[0]);
    }

    return 0;
}