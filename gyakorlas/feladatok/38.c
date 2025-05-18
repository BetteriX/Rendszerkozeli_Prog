#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define N 100

void fajlba(int a[])
{
    int f = open("kiir.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP);
    for (int i = 0; i < N; i++)
    {
        write(f, a + i, sizeof(int));
    }

    close(f);
}

void addvissza()
{
    int f = open("kiir.txt", O_RDONLY);
    int tmp;
    int tmp2;
    /*for (int i = 0; i < N; i++)
    {
        tmp = read(f, &tmp2, sizeof(int));
        printf("%d\n", tmp2);
    }*/

    lseek(f, 78 * sizeof(int), SEEK_SET);
    read(f, &tmp2, sizeof(int));
    printf("SzÃ¡m dikk: %d\n", tmp2);
    close(f);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int array[N];

    for (int i = 0; i < N; i++)
    {
        array[i] = (rand() % (0 - 1000000)) * -1;
    }
    fajlba(array);
    addvissza();
    return 0;
}