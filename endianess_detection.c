#include <stdio.h>

int main()
{
    int a = 0x12345678;
    char * ptr = (char *)&a;
    if ((*ptr & (0xf)) == 0x8)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
}