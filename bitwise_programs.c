#include <stdio.h>
#define SET(NUM,x) NUM|= (1<<x)
#define CLEAR(NUM,x) NUM&=~(1<<x)
#define TOGGLE(NUM,x) NUM^=(1<<x)
#define SWAP(a,b) temp = a;a =b;b = temp;

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);

    //count set bits
    int temp = num,count = 0;
    while(temp)
    {
        temp = temp &(temp-1);
        count++;
    }
    printf("Count Set bits: %d\n",count);

    //check power of 2
    if((num & (num-1)) == 0) 
        printf("%d is power of 2\n",num);
    else
        printf("%d is not a power of 2\n",num);
    
    //reverse the 16 bit 
    for(int i=0,j=15;i<j;j--,i++)
    {
        if (((num&(1<<i))>>i) != ((num&(1<<j))>>j))
        {
            num ^=(1<<i);
            num ^= (1<<j);
        }
    }
    printf("After reversing the number: %d\n",num);

    //extract value of 7:4 bit positions
    int value = (num & (((1<< (7-4)) - 1) << 4)) >> 4;
    printf("value of 7:4 bit positions %d\n",value);

    //set  bit
    SET(num,2);
    printf("After setting 2nd bit : %d",num);

    //clear bit
    CLEAR(num,3);
    printf("After clearing 3rd bit : %d",num);

    //toggle bit
    TOGGLE(num,4);
    printf("After toggling 4th bit : %d",num);

    //highest power of 2 <= n
    int n,highest = 1,max = 1;
    printf("Enter the number: ");
    scanf("%d",&n);
    for (size_t i = 1;i<32 ; i++)
    {
        if (highest <=n)
            break;
        highest <<= 1;
    }
    printf("highest power of 2 <=%d is %d\n",n,highest);
}