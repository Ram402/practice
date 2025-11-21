#include <stdio.h>

int main()
{
    int a = 0xAC,b = 0x53;
    int res = (a&(((1<<4)-1)<<(4))) | (b & (((1<<4)-1)<<0));
    printf("%x\n",res);
}