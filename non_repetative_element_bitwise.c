#include <stdio.h>

int main()
{
    int arr[] = {2,4,7,9,2,4,9,11},sum = 0;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        sum ^= arr[i];
    }

    int check_bit = sum & (-sum),a=0,b=0;
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        if (arr[i] & check_bit)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    printf("%d %d\n",a,b);
}