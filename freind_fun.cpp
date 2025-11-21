#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class student
{
    private:
    string name;
    int id;
    int attendance;

    public:
    student(string Name,int Id,int Attendance) : name(Name),id(Id),attendance(Attendance)
    {
        cout << "Details Added\n" << endl;
    }
    ~student()
    {
        cout << "student object destroyed"<< endl;
    }
    // friend class Attendance;

};

// class Attendance
// {
//     public:
//     void show_attendance(student s)
//     {
//         if (s.attendance == 1)
//         {
//             cout << s.name <<" is present" << endl;
//         }
//         else
//         {
//             cout << s.name <<" is absent" << endl;
//         }
//     }
// };

int main()
{
    student s1("ram",1,1);
    student s2("sai",2,0);
    // Attendance a;
    // a.show_attendance(s1);
    // a.show_attendance(s2);
    return 0;
}

// int main()
// {
//     vector<int> sensorValues = {10, 45, 70, 90, 30};
//     int limit = 60;

//     auto highValues = count_if(sensorValues.begin(), sensorValues.end(),
//                             [limit](int v){ return v > limit; });

//     cout << "Values above limit: " << highValues << endl;

// }