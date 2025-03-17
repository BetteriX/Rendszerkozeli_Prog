/*** Example of low-level file usage ***/
#include <unistd.h>   // write, read, close
#include <sys/stat.h> // S_*
#include <fcntl.h>    // O_*
#include <stdio.h>
#include <stdlib.h>

#define BlockSize 1024

int main(int argc, char *argv[])
{
  char buff[BlockSize];
  int in, out;
  int nread;
  int nums[100];

  // Opening files
  // in = open(argv[1], O_RDONLY);
  out = open("lowlevel.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH);
  FILE *file = fopen("formatted.txt", "w");

  srand(2025);

  for (int i = 0; i < 100; i++)
  {
    // int r = rand() % 10000;
    // nums[i] = r;
    nums[i] = rand() % 10000;
  }

  write(out, nums, 100 * sizeof(int));

  for (int i = 0; i < 100; i++)
  {
    fprintf(file, "%d\n", nums[i]);
  }

  // Closing the files
  close(in);
  close(out);
  fclose(file);

  return 0;
}
