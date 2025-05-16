#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int *dt(int *t1, int *t2, int db1, int db2)
{
    int *dinamikus = malloc((db1 + db2) * sizeof(int));

    int k = 0;
    for (int i = 0; i < db1; i++)
    {
        dinamikus[k] = t1[i];
        k++;
    }

    for (int i = 0; i < db2; i++)
    {
        dinamikus[k] = t2[i];
        k++;
    }

    return dinamikus;
}

void kiir(int *t, int meret)
{
    for (int i = 0; i < meret; i++)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int main()
{
    int t1[7] = {1, 2, 3, 4, 5, 6, 13};
    int size1 = 7;
    int t2[6] = {7, 8, 9, 10, 11, 12};
    int size2 = 6;

    int *dinamikt = dt(t1, t2, size1, size2);
    kiir(dinamikt, size1 + size2);
    free(dinamikt);

    return 0;
}