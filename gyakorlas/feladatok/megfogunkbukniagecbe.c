#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Bekérünk egy számot a felhasználótól és átadjuk egy másik random gyökér változónak, pipe segítségével

int main(int argc, char const *argv[])
{
    srand(getpid());
    int Pipe[2];
    pipe(Pipe); 
    int num;
    int num2;
    printf("Adj meg egy számot KÖCSÖG: ");
    scanf("%d", &num);

    write(Pipe[1], &num, sizeof(int));
    read(Pipe[0], &num2, sizeof(int));

    printf("%d = %d",num, num2);

    return 0;
}