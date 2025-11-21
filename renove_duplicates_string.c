#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    int len=0;
    while(str[len++]); len--;
    for(int i=0;i < len-1;i++)
    {
        for(int j=0;j<len;j++)
        {
            if (str[i] == str[j] && (i!=j))
            {
                for(int k=j;k<len;k++)
                {
                    str[k] = str[k+1];
                }
                len--;
            }
        }
    }
    printf("%s",str);
}