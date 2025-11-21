#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    int power;
    printf("ENter the power: ");
    scanf("%d",&power);
    num = num&((1<<power)-1);
    printf("%d\n",num); 
}