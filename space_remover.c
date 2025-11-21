#include <stdio.h>

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    int len = 0;
    while(str[len++]);
    len--;
    for(int i=0;i<len;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
    // for(int i=0;i<len;i++)
    // {
    //     if (((str[i] ==  ' ' && str[i-1] == ' ') && (i>0)) || (((str[i] == ' ') && (i==0))) || (((str[i]==' ') && (i==len))))
    //     {
    //         for(int j=i;j<len;j++)
    //         {
    //             str[j] = str[j+1];
    //         }
    //         len--;
    //         i--;
    //     }
    // }
    
    int i=0,j=0;
    if (i==0)
    {
        if(str[i] == ' ')
        {
            i++;
        }
    }
    while(str[i] !='\0')
    {
        if (str[i] != ' ' || str[i-1] != ' ')
        {
            str[j++] = str[i]; 
        }
        i++;
    }

    if (j>0 && str[j-1] == ' ')
        j--;
    for(int i=0;i<j;i++)
    {
        printf("%c,",str[i]);
    }
}