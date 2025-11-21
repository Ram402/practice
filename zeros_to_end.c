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
        for(int j=i;j<size;j++)
        {
            if (arr[i] == 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}