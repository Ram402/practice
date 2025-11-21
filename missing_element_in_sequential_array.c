#include <stdio.h>

int find_mssing_between_range(int * arr,int size,int max,int min)
{
    int sum = 0;
    for(int i=0;i<size-1;i++)
    {
        sum += arr[i];
    }
    printf("sum: %d,total:%d\n",sum,(max * (max + 1) / 2) - ((min - 1) * min / 2));
    return ((max*(max+1)/2) - (min*(min-1)/2)) - sum;
}

int main()
{
    int n=9;
    int arr[5] = {9,7,8,5};
    int max = -1,min = 10;
    for(int i=0;i<5-1;i++)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    // for(int i=0;i<9;i++)
    //     sum += arr[i];
    printf("max: %d, min: %d\n",max,min);
    printf("missing number:%d\n",find_mssing_between_range(arr,sizeof(arr)/sizeof(int),max,min));
}

