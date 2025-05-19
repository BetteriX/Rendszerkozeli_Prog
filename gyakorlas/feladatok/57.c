#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void yourslow(int sig){
    fprintf(stderr,"KURVA LASSÚ VAGY !"); // az alarm miatt leáll a program, és a custom üzenetet az error outputra rakjuk
    kill(getpid(), SIGKILL); //meggyilkolja a signalt és még rá is köpünk
}

int main(int argc, char const *argv[])
{
    int n;
    signal(SIGALRM, yourslow);
    alarm(3); // 3 másodpercre állítja be a számlálót

    printf("írj egy 3 jegyű számot: ");
    scanf("%d", &n);

    printf("%d s maradt\n",alarm(0)); // alarm(0) vissza adja a maradék időt
    printf("%d\n", n);

    return 0;
}
