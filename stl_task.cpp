#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <deque>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

int main()
{
    cout << "Vectors" << endl;
    vector<int> speed;
    for(int i=0;i<=4;i++)
    {
        int speeds;
        cout << "Enter the speed: ";
        cin >> speeds;
        speed.push_back(speeds);
    }

    for(auto v: speed)
    {
        cout << v << " ";
    }
    cout << endl;


    cout << "Deque" << endl;
    deque<string> logs;
    getchar();
    for(int i=0;i<=4;i++)
    {
        string log;
        cout << "Enter the Log: ";
        getline(cin, log);
        logs.push_back(log);
    }

    for(auto v: logs)
    {
        cout << "[Logs]  " << v << endl;
    }
    cout << endl;

        cout << "List" << endl;
    list<string> cars;
    for(int i=0;i<=4;i++)
    {
        string car;
        cout << "Enter the car Name: ";
        getline(cin, car);
        cars.push_back(car);
    }

    for(auto v: cars)
    {
        cout << v << ", ";
    }
    cout << endl;

    for(auto& v: cars)
    {
        this_thread::sleep_for(std::chrono::seconds(5));
        cout << v << " service completed" << endl;
        cars.pop_front();
    }
    cout << endl;

    cout << "set" << endl;
    set<string> Error_codes;
    for(int i=0;i<3;i++)
    {
        string err_code;
        cout << "Enter the Error Code: ";
        getline(cin, err_code);
        Error_codes.insert(err_code);
    }

    for(auto it = Error_codes.begin();it != Error_codes.end();it++)
    {
        cout << *it << endl;
    }

    cout << "map" << endl;
    map<string,string> Vehicle_data;

    for(int i=0;i<3;i++)
    {
        string vehicle_num,owner;
        cout << "Enter Vehicle number and Owner name: ";
        cin >> vehicle_num >> owner;
        Vehicle_data.insert({vehicle_num,owner});
    }

    for(auto it = Vehicle_data.begin();it != Vehicle_data.end();it++)
    {
        cout << it->first << " : " << it->second << endl;
    }

    cout << "multiset" << endl;
    multiset<int> overspeed_cnt;
    for(int i=0;i<5;i++)
    {
        int speed;
        cout << "Enter the speed: ";
        cin >> speed;
        overspeed_cnt.insert(speed);
    }
    int count=0;
    for (const auto& v:overspeed_cnt)
    {
        if (v > 100)
            count++;
    }
    cout << "Overspeed count: " << count <<  endl;

    cout << "multimap" << endl;
    multimap<string,string> Vehicle_data;
    for(int i=0;i<3;i++)
    {
        string vehicle_num,owner;
        cout << "Enter Vehicle name and Owner name: ";
        cin >> vehicle_num >> owner;
        Vehicle_data.insert({owner,vehicle_num});
    }
    int count =0,inner_cnt = Vehicle_data.size() ;
    for(auto it = Vehicle_data.begin();it != Vehicle_data.end();it++,count++)
    {
        string name = it->first;
        cout << name << " -> ";
        for(auto iit = Vehicle_data.begin();iit != Vehicle_data.end();iit++)
        {
            if (name == iit->first)
            {
                inner_cnt--;
                cout << iit->second << ", ";
            }
        }
        cout << endl;
    }
} 