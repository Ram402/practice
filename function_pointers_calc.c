#include <stdio.h>

int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div(int a,int b){return a/b;}

int main()
{
    int option,a,b;
    int (*fp[])(int,int) = {add,sub,mul,div};
    while(1)
    {
        printf("1.add\n2.Sub\n3.Mul\n4.Div\nEnter the option: ");
        scanf("%d",&option);
        if(option == 5)
            break;
        printf("Enter the num1 and num2: ");
        scanf("%d %d",&a,&b);
        if (option > 0 && option < 5)
            printf("%d \n",fp[option-1](a,b));

    }
}