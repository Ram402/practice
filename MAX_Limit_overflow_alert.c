#include <stdio.h>

#define MAX_LIMIT 10

int main()
{
    int arr[MAX_LIMIT];
    int count = 0;
    while(1)
    {
        int num;
        printf("Enter number and -1 to stop: ");
        scanf("%d",&num);
        if(num == -1)
            break;
        if(count < MAX_LIMIT)
        {
            arr[count++] = num; 
        }
        else
        {
            printf("Array is full,Elements not added\n");
        }
    } 
    for(int i=0;i<MAX_LIMIT;i++)
        printf("%d ",arr[i]);
    
    return 0;
}