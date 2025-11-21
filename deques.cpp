#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> q;
    for(int i=0;i<10;i++)
    {
        q.push_back(i+1);
    }

    for(int j=0;j<10;j++)
    {
        cout << q[j] << " ";
    }
    cout << endl;
}