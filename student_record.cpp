#include<iostream>
#include <string>
#define MAX_STUDENT 20
using namespace std;

class student
{
    private:
    string name;
    int id;
    float marks[5];
    int Attendance;
    public:
    void addStudent()
    {
        cout << "Student Details" << endl;
        cout << "Student Name: ";
        getchar();
        getline(cin,name);
        cout << "Student Id: ";
        cin >> id;
        cout << "Student marks" << endl;
        for(int i=0;i<5;i++)
        {
            cout << "subject " << i+1 << ": ";
            cin >> marks[i];
        }
        cout << "Student Attendance(1 for present,0 for Absent): ";
        cin >> Attendance;
    }

    void display_student_data()
    {   
        int i,sum = 0;     
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Total Marks: " ;
        for(i=0;i<5;i++)
        {
            sum += marks[i];
        }
        cout << sum << "/500" << endl << "Attendance: ";
        if (Attendance == 1)
            cout << "present" << endl;
        else
            cout << "Absent" << endl;
    }

    friend int search_student(student s,int Id);
};

int search_student(student s,int Id)
{
    if (s.id == Id)
    {
        cout << "student found" << endl;
        s.display_student_data();
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int count = 0,choice;
    student data[MAX_STUDENT];
    while(true)
    {
        cout << "1.Add student\n2.Display all students\n3.Search student by id\n4.Exit" << endl;
        cout << "Enter the option: ";
        cin  >> choice;
        switch (choice)
        {
            case 1:
            {
                if (count == MAX_STUDENT)
                {
                    cout << "No seats Available" << endl;

                }
                else
                {
                    student s;
                    s.addStudent();
                    data[count++] = s;
                }
                break;
            }
            case 2: for(int i=0;i<count;i++)
                    { 
                        data[i].display_student_data();
                    }
                break;
            case 3: 
                {   int Id,flag = 0;
                    cout << "Enter the id to search: ";
                    cin >> Id;
                    for(int i=0;i<count;i++)
                    {
                        if (search_student(data[i],Id) == 0)
                        {
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        cout << "No student found on this Id " << Id << endl;
                
                    break;
                } 
            case 4:return 0;
            default:
                cout << "Invalid option" << endl;
                cout << "Please Enter correct option" << endl;
        }
    }
    return 0;
}