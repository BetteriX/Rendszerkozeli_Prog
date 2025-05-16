#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    char input[100];
    time_t start, end;
    printf("Leghoszabb szó: ");

    time(&start);
    scanf("%s", input);
    time(&end);

    // printf("Start idő: %ld\n", start);
    // printf("End idő: %ld\n", end);

    int eltelt_ido = end - start;
    printf("Eltelt ido: %d s\n", eltelt_ido);
    return 0;
}