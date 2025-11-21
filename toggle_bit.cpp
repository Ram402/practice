#include<iostream>
using namespace std;
 
int main()
{
    int n = 2;      // number of bits
    int pos = 3;    // position for shifting

    // 1. Toggling n-th bit
    int num3 = 10; // 0000 1010
    num3 = num3 ^ (1 << n);
    cout << "After toggling " << n << "th bit from LSB: " << num3 << endl;
    // toggles bit-2 → 0000 0010 → 2
 
    // 2. Toggling N bits from LSB
    int num4 = 10; // 0000 1010
    num4 = num4 ^ ((1 << n) - 1);
    cout << "After toggling N bits from LSB: " << num4 << endl;
    // toggles last 2 bits → 0000 1001 → 9
 
    // 3. Toggling N bits from a position
    int num5 = 10; // 0000 1010
    num5 = num5 ^ (((1 << n) - 1) << pos);
    cout << "After toggling N bits from pos: " << num5 << endl;
    // toggles bits at pos=3 → 0001 0010 → 18

    return 0;
}

 