/*** Example of inode reading ***/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <dirent.h>

#define ONE_WEEK_SECOND (7 * 24 * 60 * 60)

int main(int argc, char *argv[])
{
  DIR *d;
  struct dirent *entry;
  struct stat inode;
  time_t now = time(NULL);

  d = opendir("..");
  if (d == NULL)
  {
    fprintf(stderr, " opendir error.\n");
    return 1;
  }

  while ((entry = readdir(d)) != NULL)
  {
    if ((*entry).d_name[0] == '.')
    {
      continue;
    }

    if (sat((*entry).d_name, &inode) == 0)
    {
      if ((inode.st_mode & S_IFREG) && (now - inode.st_mtime) > ONE_WEEK_SECOND)
      {
        printf("%s\n", (*entry).d_name);
      }
      else
      {
        fprintf(stderr, "inode error\n");
      }
    }
    closedir(d);
  }
  return 0;
}
