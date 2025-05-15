#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *home = getenv("HOME");
    char *pwd = getenv("PWD");

    if (strcmp(home, pwd) == 0)
    {
        printf("Igen!\n");
    }
    else
    {
        printf("Nem!\n");
    }
    return 0;
}