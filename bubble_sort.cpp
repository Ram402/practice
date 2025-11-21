#include<iostream>
#include <array>
using namespace std;

int main()
{
    array<int,10> arr = {8,7,4,0,1,4,5,2,9,3};
    // cout << "Enter 10 elements: ";
    // for(int i=0;i<10;i++)
    // {
    //     cin >> arr[i];
    // }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int& i:arr)
    {
        cout << i << " ";
    }

}