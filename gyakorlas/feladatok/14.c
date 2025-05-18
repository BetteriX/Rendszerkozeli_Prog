#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    unsigned int seed = t->tm_year * 10000 +
                        t->tm_mon * 1000 +
                        t->tm_mday * 100 +
                        t->tm_hour * 10 +
                        t->tm_min;

    srand(seed);

    int randomNumber = rand() % 999999 + 1;

    printf("%d\n", randomNumber);

    return 0;
}
