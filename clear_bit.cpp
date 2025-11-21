#include<iostream>
using namespace std;
 
int main()
{
    int n = 2;      // number of bits
    int pos = 3;    // position for shifting
 
    // 1. Clearing n-th bit
    int num = 10; // 0000 1010
    num = num & ~(1 << n);
    cout << "After clearing " << n << "th bit from LSB: " << num << endl;  
    // clears bit-2 → 0000 0010 → 2
 
 
    // 2. Clearing N bits from LSB
    int num1 = 10; // 0000 1010
    num1 = num1 & ~((1 << n) - 1);
    cout << "After clearing N bits from LSB: " << num1 << endl;
    // clears last 2 bits → 0000 1000 → 8
 
 
    // 3. Clearing N bits from a position
    int num2 = 10; // 0000 1010
    num2 = num2 & ~(((1 << n) - 1) << pos);
    cout << "After clearing N bits from pos: " << num2 << endl;
    // clears 2 bits at pos=3 → no change for 10 → remains 10
 
    return 0;
}