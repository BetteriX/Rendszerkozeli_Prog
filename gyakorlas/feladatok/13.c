#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int also, int felso)
{
    return also + (rand() % (felso - also + 1));
}

int main()
{
    srand(time(NULL));

    int rand1 = randint(0, 1000);
    int rand2 = randint(0, 1000);

    int ertek;
    if (rand1 < rand2)
    {
        ertek = randint(rand1, rand2);
        printf("[%d;%d] = ", rand1, rand2);
    }
    else
    {
        ertek = randint(rand2, rand1);
        printf("[%d;%d] = ", rand2, rand1);
    }

    // printf("1. ertek: %d\n2. ertek: %d\n", rand1, rand2);
    printf("%d\n", ertek);

    return 0;
}