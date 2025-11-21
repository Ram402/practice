#include <stdio.h>

int main()
{
    int num,rot;
    printf("Enter the number and number of times to rotate: ");
    scanf("%d %d",&num,&rot);

    rot = rot & 31;
    printf("Left shift : %d",(num << (rot)) | (num >> (32 - rot)));
    printf("Right shift: %d",(num << (32 - rot)) | (num >> (rot)));
}