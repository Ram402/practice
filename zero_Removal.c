#include <stdio.h>

int remove_zeros(int * arr,int size)
{
    int i=0,j=0;

    while(i < size)
    {
        if (arr[i] != 0)
        {
            arr[j++] = arr[i];
        }
        i++;
    }
    return j;
}

int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int size = remove_zeros(arr,10);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    } 
}