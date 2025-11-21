#include <stdio.h>

int is_palindrome(int num)
{
    int rev_num = 0,temp = num;
    while(num)
    {
        rev_num = (num%10) + (rev_num * 10);
        num /= 10;
    }
    if (rev_num == temp)
        return 0;
    return 1;
}


int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    int res = is_palindrome(num);
    if (res == 0)
    {
        printf("%d is a palindrome\n",num);
    }
    else   
    {
        printf("%d is not a palindrome\n",num);
    }
}