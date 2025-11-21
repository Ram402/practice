#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int,10> arr = {8,7,4,0,1,4,5,2,9,3};
    for(int i=0;i<10-1;i++)
    {
        int mindex =i;
        for(int j=i+1;j<10;j++)
        {
            if(arr[i] < arr[mindex])
                mindex = i;
        }
        swap(arr[i],arr[mindex]);
    }
    for(int i:arr)
        cout << i << " ";
}