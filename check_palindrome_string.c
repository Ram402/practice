#include <stdio.h>

int is_palindrome(char * str)
{
    int len = 0;
    while(str[len++]);
    len--;
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if (str[i] != str[j])
            return 1;
    }
    return 0;
}

int main()
{
    char str[10];
    printf("Enter the string: ");
    scanf(" %[^\n]",str);
    int res = is_palindrome(str);
    if (res == 0)
        printf("%s is a palindrome\n",str);
    else
        printf("%s is not a palindrome\n",str);   
}