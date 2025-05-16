#include <stdio.h>

void ertekfelcserel(int *param1, int *param2)
{
    int tmp = *param1;
    *param1 = *param2;
    *param2 = tmp;
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
    int meret = 5;
    int t1[5] = {2, 5, 3, 8, 4};

    printf("Előtte: ");
    kiir(t1, meret);
    ertekfelcserel(&t1[2], &t1[0]);

    printf("Utána: ");
    kiir(t1, meret);

    return 0;
}