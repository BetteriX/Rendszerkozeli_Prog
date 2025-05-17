#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

int main()
{
    DIR *d;
    struct dirent *entry;

    d = opendir(".");
    while ((entry = readdir(d)) != NULL)
    {
        char *str = (*entry).d_name;
        char *cp;
        strncpy(cp, str + (strlen(str) - 4), 5);

        // 1234 5
        // .txt\0

        if (strcmp(cp, ".txt") == 0)
        {
            printf("%s\n", str);
        }
    }
    return 0;
}