#include <stdio.h>
#define SWAP(a,b) a = a^b;b=a^b;a=a^b

int main()
{
    int num1 = 1,num2 =2;
    printf("Before Swapping num1 = %d, num2 = %d\n",num1,num2);
    SWAP(num1,num2);
    printf("After Swapping num1 = %d, num2 = %d",num1,num2);
}