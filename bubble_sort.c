#include <stdio.h>

#define SWAP(DTYPE,a,b) DTYPE temp = a; \
                        a = b;          \
                        b = temp;

int main()
{
    int arr[10]= {4,7,2,1,9,0,3,2,8,5};

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 9 - i; j++)
        {
            if(arr[j] > arr[j+1])
                {SWAP(int, arr[j], arr[j+1]);}
        }
    }

    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
