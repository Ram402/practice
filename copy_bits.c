#include <stdio.h>

void print_binary(int num)
{
    for(int i=7;i>=0;i--)
        if (num & (1<<i))
            printf("1");
        else
            printf("0");

    printf("\n");
}


int main()
{
    int dest,src,pos,len;
    printf("Enter the dest: ");
    scanf("%d",&dest);
    print_binary(dest);
    printf("Enter the src: ");
    scanf("%d",&src);
    print_binary(src);
    printf("Enter the pos: ");
    scanf("%d",&pos);
    printf("Enter the len: ");
    scanf("%d",&len);

    int temp = src & ((1<<len)-1);
    dest &= ~(((1<<len)-1)<<pos);
    dest |= (temp & ((1<<len)-1)) << pos;
    printf("%d\n",dest);
    print_binary(dest);
}