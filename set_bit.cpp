#include<iostream>
using namespace std;
int main()
{
    int n = 2;
    // setting nth bit
    int num = 10; // 0000 1010
    num = num| (1<<n);
    cout <<"After setting 2nd bit from LSB is " << num << endl ;    // 0000 1110 in binary so in decimal 14
 
    // seting n bits from LSB
    int num1 = 10; // 0000 1010
    num1 = num1 | ((1<<n)-1);
    cout <<"After setting N bits from LSB is " << num1 << endl;    // 0000 1011 in binary so in decimal 11
 
    // setting nbits from pos from msb
    int pos = 3;
    int num2 = 10; // 0000 1010
    num2 = num2 | (((1<<n)-1) << pos);
    cout <<"After setting N bits from pos is " << num2 << endl;    // 0001 1010 in binary so in decimal 26
}