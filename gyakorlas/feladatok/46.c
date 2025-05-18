#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    struct stat inode;
    struct dirent *entry;
    DIR *d;

    d = opendir(".");

    int tmp;
    double li = 0;

    while ((entry = readdir(d)) != NULL)
    {
        tmp = stat((*entry).d_name, &inode);

        if (inode.st_mode & __S_IFREG)
        {
            li += (double)inode.st_size / 1024;
            printf("%s %lf kB\n", (*entry).d_name, (double)inode.st_size / 1024);
        }
    }

    closedir(d);

    printf("Össz: %lf kB\n", li);
    return 0;
}
