#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,col;
    printf("Enter the row and col: ");
    scanf("%d %d",&row,&col);
    int ** arr = (int**)malloc(row*(sizeof(int*)));
    for(int i=0;i<row;i++)
        arr[i] = (int *)malloc(col *(sizeof(int)));
    
    int num =0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr[i][j] = num++;
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("After transpose\n");
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }

    for(int i=0;i<row;i++)
        free(arr[i]);
    free(arr);
}