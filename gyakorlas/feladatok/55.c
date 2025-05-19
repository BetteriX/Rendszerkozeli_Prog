#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    srand(getpid());
    int Pipe[2];
    pipe(Pipe);

    __pid_t pid;
    pid = fork(); // megfarkaljuk a pidet gyerek folyamatért

    int num;

    if (pid == 0)
    {
        num = getpid();
        close(Pipe[0]); // bezárjuk az olvasási végét a pipenak
        write(Pipe[1], &num, sizeof(int));
    }
    else
    {
        close(Pipe[1]); // bezárjuk az írási végét a pipenak
        read(Pipe[0], &num, sizeof(int));
        if (num == pid) // pid tárolja a gyerek folyamat folyamatazonosítóját
        {
            printf("Ez az én fiam!\n");
        }
        else
            printf("TE KI VAGY? ");
    }

    return 0;
}