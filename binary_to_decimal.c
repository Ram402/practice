#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char str[100];
    printf("Enter the binary number: ");
    scanf("%s",str);
    int len = strlen(str);
    int sum = 0,j=0;
    for(int i=len-1;i>=0;i--)
    {
        if (str[i]== '1')
        {
            sum += (pow(2,j));
        }
        j++;
    }
    printf("Decimal number: %d\n",sum);
    return 0;
}