#include <fcntl.h>    // O_*
#include <unistd.h>   // write, read, close
#include <sys/stat.h> // S_*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[1000];

    srand(2025);

    for (int i = 0; i < 1000; i++)
    {
        nums[i] = rand() % 1000;
    }

    int out = open("numbers.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
    write(out, nums, 1000 * sizeof(int));
    close(out);

    FILE *f = fopen("reference.txt", "w");
    for (int i = 0; i < 1000; i++)
    {
        fprintf(f, "%d\n", nums[i]);
    }

    int in = open("numbers.txt", O_RDONLY);
    lseek(in, 871 * sizeof(int), SEEK_SET);

    int result;
    read(in, &result, sizeof(int)); // csak 1 db int
    printf("Result: %d\n", result);
    printf("In array: %d\n", nums[871]);

    close(in);
    fclose(f);

    return 0;
}