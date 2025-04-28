#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *tomb, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int s = rand() % N;

        int tmp = tomb[i];
        tomb[i] = tomb[s];
        tomb[s] = tmp;
    }
}

void kiir(int *tomb, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", tomb[i]);
    }
    printf("\n");
}

int main()
{
    srand(2025);
    // srand(time(NULL));

    int t[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int N = 10;

    kiir(t, N);
    shuffle(t, N);
    kiir(t, N);

    return 0;
}