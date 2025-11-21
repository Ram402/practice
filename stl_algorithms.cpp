#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool even(int x)
{
    
    return x %2==0;
}


int main()
{
    vector<int> v = {1,5,6,3,9,7,4,10};
    vector<int> dest(3);
    vector<int> v2 = {1,5,6,3,9,7,4,10};
    vector<int> result(v.size()+v2.size());
    copy(v.begin(),v.end(),dest.begin());
    partition(v.begin(),v.end(),even);
    replace_if(v.begin(),v.end(),even,0);
    merge(v.begin(),v.end(),v2.begin(),v2.end(),result.begin());
    for(auto v: result)
    {
        cout << v << endl;
    }
    sort(v.begin(),v.end());
    for(auto v: v)
    {
        cout << v << endl;
    }
    auto rem = remove_if(v.begin(),v.end(),[](int x){return x%2 == 0;});
    v.erase(rem,v.end());
    cout << *rem << endl;
    for(auto v: v)
    {
        cout << v << endl;
    }
    reverse(v.begin(),v.end());
    for(auto v: v)
    {
        cout << v << endl;
    }

    auto it = adjacent_find(v.begin(),v.end());
    cout << *it << endl;

    bool res = equal(v.begin(),v.end(),v2.begin());
    cout << res << endl;
}