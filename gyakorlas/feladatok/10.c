#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    time_t T1;
    struct tm *T2;

    while (1)
    {
        time(&T1);
        T2 = localtime(&T1);
        printf("%d\n", 60 - (*T2).tm_sec);
        sleep(1);
        if ((60 - (*T2).tm_sec) == 30)
        {
            system("sudo reboot now");
        }
    }

    return 0;
}