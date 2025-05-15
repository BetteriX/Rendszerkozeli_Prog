#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main()
{
    char *username = getenv("USER");

    char hostname[100];
    gethostname(hostname, sizeof(hostname));

    printf("%s@%s\n", username, hostname);
    return 0;
}