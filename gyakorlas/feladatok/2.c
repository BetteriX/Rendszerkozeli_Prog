#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ertek = atoi(argv[1]);
    // int ertek = argv[1] - '0';
    printf("%d\n", ertek * ertek);
    return 0;
}