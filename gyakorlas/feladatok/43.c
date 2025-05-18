#include <stdio.h>
#include <stdlib.h>
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

        size_t len = strlen(str);
        if (len < 4)
            continue;

        /* compare the last 4 chars with ".txt" */
        if (strcmp(str + len - 4, ".txt") == 0)
        {
            printf("%s\n", str);
        }

        /*
        char *cp;
        strncpy(cp, str + (strlen(str) - 4), 5);

        // 1234 5
        // .txt\0

        if (strcmp(cp, ".txt") == 0)
        {
            printf("%s\n", str);
        }
        */
    }

    closedir(d);

    return 0;
}