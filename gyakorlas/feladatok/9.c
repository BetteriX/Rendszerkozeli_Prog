#include <stdio.h>

#if defined(linux) || defined(_linux) || defined(__linux__) || defined(__unix__)
#define OSTYPE 1
#else
#define OSTYPE 0
#endif

int main()
{
    if (OSTYPE == 1)
    {
        printf("Hello World!\n");
    }
    return 0;
}