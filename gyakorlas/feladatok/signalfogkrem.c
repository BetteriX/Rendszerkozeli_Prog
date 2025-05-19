#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void bef(int sig){

    printf("\nA program leáll!\n");
    exit(1);
}

int main(int argc, char const *argv[])
{
    int n = 0;
    signal(SIGINT, bef);
    while (1)
    {
        scanf("%d", &n);
    }

    return 0;
}