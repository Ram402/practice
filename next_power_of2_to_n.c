#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    
    for(int i=0;i<32;i++)
        if((1<<i) >= num)
            {printf("%d\n",(01<<i));break;}
}