#include <stdio.h>

int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int num1 = arr[0],num2 = arr[1],max= num1+num2;
    for(int i=2;i<10;i++)
    {
        if ((arr[i]+arr[i-1]) > max)
        {
            max = arr[i]+arr[i-1];
            num1 = arr[i-1];
            num2 = arr[i];
        }
    }
    printf("max:%d\nnum1:%d,num2:%d\n",max,num1,num2);
}