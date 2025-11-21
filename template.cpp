#include <iostream>

using namespace std;

template <typename t> void add(t a,string b)
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    add<int>(14,"ram");

}

