#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int zseton = 10;
    int dobas = 0;

    while (zseton != 0 && zseton != 20)
    {
        // 0 -> Fej, 1 -> Írás
        int randint = rand() % 2;

        if (randint == 0)
        {
            zseton++;
        }
        else
        {
            zseton--;
        }

        dobas++;
    }

    printf("Ennyit dobott: %d\n", dobas);

    if (zseton == 0)
    {
        printf("Vesztettél!\n");
    }
    else
    {
        printf("Nyertél!\n");
    }

    return 0;
}