#include <iostream>
#include<memory>
using namespace std;

class St
{
    public:
    int n = 10;
    string name = "sai";
    
    St() {}
    St(int num,string nam) {n = num;name = nam;}    
};


St obj21;

int main()
{
    St obj1;
    St obj2(11,"ram");
    cout << obj1.n << " " << obj1.name << endl;
    cout << obj2.n << " " << obj2.name << endl;
    cout << obj21.n << " " << obj21.name << endl;

}