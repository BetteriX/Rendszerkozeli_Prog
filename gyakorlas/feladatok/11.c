#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t T1;
    struct tm *T2;

    time(&T1); // Inicializálás
    T2 = localtime(&T1);
    int week = (*T2).tm_wday;
    // 6 és 0 -> Hétvége; 1,2,3,4,5 -> Hétköznap
    if (week == 6 || week == 0)
    {
        printf("Hétvége van!\n");
    }
    else
    {
        printf("Hétköznap van!\n");
    }
    return 0;
}