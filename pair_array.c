#include <stdio.h>

int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int num,size =10;
    printf("Enter the nmber: ");
    scanf("%d",&num);

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if (((arr[i]+arr[j]) == num) )//&& (i!=j))
            {
                printf("(%d,%d)",arr[i],arr[j]);
            }
        }
    }
}