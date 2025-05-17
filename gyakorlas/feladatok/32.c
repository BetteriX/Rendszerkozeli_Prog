#include <stdio.h>

unsigned int swap_bytes(unsigned int x)
{
    int result = 0;
    int byte, i;
    int one_byte_mask = (1 << 8) - 1;

    for (i = 0; i < 4; i++)
    {
        byte = (x >> (i * 8)) & one_byte_mask;
        printf("byte: %d -> ", byte);
        result |= byte << ((3 - i) * 8);
        printf("%d\n", result);
    }
    return result;
}

int main(void)
{
    unsigned int a = 308276097;
    printf("%u\n", a);

    unsigned int b = swap_bytes(a);
    printf("%u\n", b);
    unsigned int c = swap_bytes(b);
    printf("%u\n", c);

    return 0;
}