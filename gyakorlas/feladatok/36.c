#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("nums2.txt", "r+");

    int num;
    long pos;

    while (fscanf(f, "%d", &num) == 1)
    {
        pos = ftell(f); // Aktuális pozíció
        if (num >= 100 && num <= 199)
        {
            int new_num = num * 2;

            fseek(f, pos - 3, SEEK_SET); // Visszalép 3 karaktert
            fprintf(f, "%3d", new_num);  // Felülírja 3 számjeggyel
            fseek(f, pos, SEEK_SET);     // Visszalép az eredeti helyére
        }
    }

    fclose(f);
    return 0;
}
