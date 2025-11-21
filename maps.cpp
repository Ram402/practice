#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string,int> marks;

    for(int i=0;i<=2;i++)
    {
        string subject;
        int mark;
        cout << "Enter the subject: ";
        cin >> subject;
        cout << "Enter the marks: ";
        cin >> mark;
        marks.insert({subject,mark});
    }

   for (auto p : marks)
    {
        cout << p.first << ": " << p.second << endl;
    }
}