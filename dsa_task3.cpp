#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
    stack<string> commnads;
    queue<string> sensorData;
    priority_queue<pair<int,string>> emergencyEvents;
    string data;
    int prority,opt;
    while(1)
    {
        cout << "\n1.Add Sensor Data\n2.Process next sensor data\n3.Add emergency event\n4.Handle top priority\n5.Add manual command\n6.Undo last command\n7.Display all data\n8.Exit\n\nEnter the option: ";
        cin >> opt;
        switch(opt)
        {
            case 1:
                {
                    cout << "Enter the data: ";
                    getchar();
                    getline(cin,data);
                    sensorData.push(data);
                    break;
                }
            case 2:
                {
                    cout << "Processing data: " << sensorData.front() << endl;
                    sensorData.pop(); cout << "Proccessed" << endl; 
                    break;
                }
            case 3:
                {
                    cout << "Enter the priority: ";
                    cin >> prority;
                    cout << "Enter the event: ";
                    getchar();
                    getline(cin,data);
                    emergencyEvents.push({prority,data});
                    break;
                }
            case 4:
                {
                    cout << "Handling Event: " <<  emergencyEvents.top().second << endl;
                    cout << "Emergency resolved" << endl; emergencyEvents.pop();
                    break; 
                }
            case 5:
                {
                    cout << "Enter the command: ";
                    getchar();
                    getline(cin,data);
                    commnads.push(data);
                    break;
                }
            case 6:
                {
                    cout << "Last Command: " << commnads.top() << endl;
                    commnads.pop();
                    break;
                }
            case 7:
                {

                    // for_each(sensorData.begin(),sensorData.end(),[](string data) {cout << data << endl;})
                    cout << "====== Sensors Data ======" << endl;
                    queue<string> temp = sensorData;
                    while(!(temp.empty()))
                    {
                        cout << temp.front() << endl;
                        temp.pop();
                    }

                    cout << endl << endl << "====== Emergency Events ======" << endl;
                    priority_queue<pair<int,string>> temper = emergencyEvents;
                    while(!(temper.empty()))
                    {
                        cout << "(" << temper.top().first << "," << temper.top().second << ")" << endl;
                        temper.pop();
                    }

                    cout << endl << endl << "====== Commands =======" << endl;
                    stack<string> temperary = commnads;
                    while(!(temperary.empty()))
                    {
                        cout << temperary.top() << endl;
                        temperary.pop();
                    }
                    break;
                }
            case 8:
                exit(0);
        }
    }
}