#include <stdio.h>

void remove_duplicates(char * str)
{
    int i=0,j=0;
    int arr[257] = {0};

    while(str[i] != '\0')
    {
        if (!(arr[str[i]]))
        {
            arr[str[i]] = 1;
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]",str);

    remove_duplicates(str);
    printf("After removing duplicates: %s\n",str);
}