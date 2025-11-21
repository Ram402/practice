#include <stdio.h>

void dec_to_bin(int num,int * arr,int * size)
{
    int i=0;
    if (num == 0)
    {
        arr[i] = 0;
        *size = 1;
        return;
    }
    while(num)
    {
        arr[i++] = num%2;
        num /= 2;
    }
    *size = i;
    return;
}

int main()
{
    int num;
    printf("Enter the decimal number: ");
    scanf("%d",&num);
    int arr[32],size;
    dec_to_bin(num,arr,&size);
    for(int i=size-1;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}