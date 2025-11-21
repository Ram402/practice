#include <stdio.h>

void reverse(int arr[],int start,int end)
{
    for(int i=start,j=end;i<j;i++,j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int arr[10];
    printf("Enter the array elements: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int size = 10,pos;
    printf("Enter number of times to rotate: ");
    scanf("%d",&pos);
    reverse(arr,0,pos-1);
    reverse(arr,pos,size-1);
    reverse(arr,0,size-1);

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}