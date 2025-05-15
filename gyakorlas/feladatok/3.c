#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *cmd;
    sprintf(cmd, "cp %s last", argv[0]);
    system(cmd);

    return 0;
}