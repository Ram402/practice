#include <stdio.h>

int main()
{
    char str[50];
    printf("Enter the string: ");
    scanf("%[^\n]",str);

    int max_len = 0,start_index = 0,right = 0,left = 0;
    char freq[256]={0};

    while(str[right] != '\0')
    {
        freq[str[right]]++;

        while(freq[str[right]] > 1)
        {
            freq[str[left]]--;
            left++;
        }

        int size = right  - left+1;
        if ( size > max_len)
            {max_len = size;start_index = left;}
        
        right++;
    }
    for(int i=start_index;i<start_index+max_len;i++)
    {
        printf("%c",str[i]);
    }
    printf("\nmax_len: %d\n",max_len);
}