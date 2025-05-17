#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("nums.txt", "r+"); // Olvasás és írás

    int sum = 0;
    int num;

    while (fscanf(f, "%d", &num) == 1)
    { // 1 ha a végére ért
        sum += num;
    }
    printf("Összeg: %d\n", sum);

    fseek(f, 0, SEEK_END); // A végére megy

    fprintf(f, " %d", sum);

    fclose(f);
    return 0;
}