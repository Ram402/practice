#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    vector<vector<int>> matrix(3,vector<int>(3));
    if (v.empty())
    {
        cout << "vector is empty" << endl;
    }
    for(int i=10-1;i>=0;i--)
    {
        v.push_back(i+1);
    }
    v.insert(v.begin()+0,11);

    v.erase(find(v.begin(),v.end(),5));
    for(auto v: v)
    {
        cout << v << endl;
    }
    cout << "size of the vector: " << v.size() << "\ncapacity of the vector: " << v.capacity() << endl;
    int n=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            matrix[i][j] = n++;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    v.pop_back();
    for(auto v: v)
    {
        cout << v << " ";
    }
        v.erase(v.begin()+2);
    v.clear();
    for(auto v: v)
    {
        cout << v << " ";
    }
    cout << "Array cleared" << endl;

    for(auto v: v)
    {
        cout << v << " ";
    }
}