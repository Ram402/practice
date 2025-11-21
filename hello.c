#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     int * ptr = (int*)malloc(sizeof(int));
//     *ptr = 2;
//     printf("%d",*ptr);
//     if(printf("Hello World")){}
//     return 0;
// }

#define PRINT_NUM(x) for(int i=0;i<x;i++) { \
                            printf("%d ",i); }          
                                           

int main()
{
    PRINT_NUM(10);
}

