#include <stdio.h>
#include <string.h>

void  str_rev(char * str)
{
    char * start = str,*end = str + (strlen(str)-1);
    while(end > start)
    {
        *(start)   = (*start)^(*end);
        *(end) = (*start)^(*end);
        *(start)   = (*start)^(*end);
        end--;
        start++;
    }
}

int main()
{
    char str[10];
    printf("ENter the string:");
    scanf("%s",str);
    str_rev(str);
    printf("%s",str);
}