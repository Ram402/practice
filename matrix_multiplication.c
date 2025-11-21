#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **arr1 = NULL,**arr2 = NULL,**arr3 = NULL,row,col;
    printf("Enter the row and col: ");
    scanf("%d %d",&row,&col);
    arr1 = (int**)malloc(row*sizeof(int*));
    if(arr1 == NULL)
    {
        perror("malloc: ");
        return 1;
    }
    arr2 = (int**)malloc(row*sizeof(int*));
    if(arr2 == NULL)
    {
        perror("malloc: ");
        return 1;
    }
    arr3 = (int**)malloc(row*sizeof(int*));
    if(arr3 == NULL)
    {
        perror("malloc: ");
        return 1;
    }
    for(int i=0;i<row;i++)
    {
        arr3[i] = (int*)malloc(col*(sizeof(int)));
        if (arr3[i] == NULL)
        {
            perror("malloc: ");
            return 1;
        }
    }

    for(int i=0;i<row;i++)
    {
        arr1[i] = (int*)malloc(col*(sizeof(int)));
        if (arr1[i] == NULL)
        {
            perror("malloc: ");
            return 1;
        }
        for(int j=0;j<col;j++)
        {
            printf("Enter the elements in array1[%d][%d]: ",i+1,j+1);
            scanf("%d",&arr1[i][j]);
        }
    }
    
    for(int i=0;i<row;i++)
    {
        arr2[i] = (int*)malloc(col*(sizeof(int)));
        if (arr2[i] == NULL)
        {
            perror("malloc: ");
            return 1;
        }
        for(int j=0;j<col;j++)
        {
            printf("Enter the elements in array2[%d][%d]: ",i+1,j+1);
            scanf("%d",&arr2[i][j]);
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            arr3[i][j] = 0;
            for(int k=0;k<col;k++)
            {
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",arr3[i][j]);
        }
    }
}