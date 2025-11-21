#include <stdio.h>
#include <stdlib.h>
// hiii
int main()
{
    int row = 3,col = 3,num = 1;
    int * ptr = (int *)malloc(row*col*(sizeof(int)));                                                                                                                                                                                                                                                                           
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            ptr[i*col+j] = num++; 
        }
    }
    int (*arr)[3] = (int (*)[3])ptr;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }

}
