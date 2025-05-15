#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // env | cut -d '=' -f 1  → csak a neveket vágja ki
    // >&2                  → a kimenetet stderr-re irányítja
    system("env | cut -d '=' -f 1 >&2");
    return 0;
}