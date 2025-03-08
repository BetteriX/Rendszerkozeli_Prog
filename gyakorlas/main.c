#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%d: %s\n", i, argv[i]);
        // fprintf(stdout, "%d: %s\n", i, argv[i]);
        // ./a.out alma 567 -f 8.9 > out.txt
    }

    printf("Az aktuális mappa:\n");
    system("ls -l");

    return 0;
}