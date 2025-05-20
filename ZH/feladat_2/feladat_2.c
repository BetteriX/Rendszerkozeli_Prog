#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int stop = 0;
int ai = 0;

void sign(int sig)
{
    stop = 1;
}

int main()
{
    signal(SIGINT, sign);

    char domain[100];

    while (!stop)
    {
        printf("Adjon meg egy stringet: ");
        // scanf("%s", domain); -> nem lesz jó ide nem tud kilépni valamiért...
        fgets(domain, sizeof(domain), stdin);

        domain[strcspn(domain, "\n")] = '\0';

        int len = strlen(domain);
        if (len >= 3 && strcmp(domain + len - 3, ".ai") == 0)
        {
            ai++;
        }
    }

    printf("A .ai végű stringek száma: %d\n", ai);

    return 0;
}
