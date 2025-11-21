#include <stdio.h>

void str_rev(char str[])
{
    int len= 0;
    while(str[len++]);
    len--;
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    // printf("reversed string: %s\n",str);
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    str_rev(str);
    int len = 0;
    while(str[len++]);
    len--;
    // printf("%s",str);
    int start = 0,end = 0;
    for(int i=0;i<=len;i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {

            for( start,end=i-1;start<end;start++,end--)
            {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
            }
            start = i+1;
        }
    }
    printf("reversed string: %s\n",str);
}