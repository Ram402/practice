#include <stdio.h>

int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int size = 10;
    for(int i=0;i<size;i++)
    {

        if (arr[i] == 0)
        {
            for(int k=i;k<size;k++)
            {
                arr[k] = arr[k+1];
            }
            size--;
            i--;
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}