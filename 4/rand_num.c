#include <stdio.h>
#include <stdlib.h>

int randint(int also, int felso)
{
    return also + (rand() % (felso - also + 1));
}

int main()
{
    srand(2025);
    FILE *f = fopen("numbers.txt", "w+");

    if (f == NULL)
    {
        fprintf(stderr, "There is a file opening problem!\n");
        return 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        // int rnd = rand() % 1000
        fprintf(f, "%d\n", randint(1, 1000));
    }

    fseek(f, 0, SEEK_SET);

    int num;
    for (int i = 0; i < 872; i++)
    {
        fscanf(f, "%d", &num);
    }

    printf("%d\n", num);

    fclose(f);

    return 0;
}