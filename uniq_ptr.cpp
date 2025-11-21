#include <iostream>
#include <memory>
using namespace  std;

int main()
{
    unique_ptr<int[]> ptr = make_unique<int[]>(3);
    for(int i=0;i<3;)
    {
        ptr[i] = i++;
    }

    for(int i=0;i<3;i++)
    {
        cout << ptr[i] << " ";
    }
    
}