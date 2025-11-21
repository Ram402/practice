#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
// #define RAND_MAX 120
using namespace  std;

int data()
{
   int speed = (rand()%100);
    return speed;    
}

int main()
{
    cout << "---- For each, Min, Max ----" << endl;
    vector<int> car_speed(10);
    for(auto& v:car_speed)
    {
        v = data();
    }
    auto min = min_element(car_speed.begin(),car_speed.end());
    auto max = max_element(car_speed.begin(),car_speed.end());
    cout << "Min: " << *min << endl << "Max: " << *max << endl << "Car speeds" << endl;
    for_each(car_speed.begin(),car_speed.end(),[](int x){cout << x << " ";}); 
    cout << endl;

    cout << "---- Find ----" << endl;
    deque<string> fault_code = {"P0010", "P0128", "P0301","P0402","P0507"};
    cout << "Enter the fault code: ";
    string code;
    cin >> code;
    auto pos = find(fault_code.begin(),fault_code.end(),code);
    if (pos == fault_code.end())
    {
        cout << "Fault code not found" << endl;
    } 
    else
    {
        cout << "Fault code found at position: " << (pos- fault_code.begin()) << endl;
    }

    cout << "---- Copy ----" << endl;
    list<int> sensor_data(5);
    list<int> backup_data(sensor_data.size());
    cout << "Ultrasonic sensor data: ";
    for(auto& v:sensor_data)
    {
        v = data();
        cout << v << " ";
    }
    cout << endl << "Creating Backup" << endl;
    copy(sensor_data.begin(),sensor_data.end(),backup_data.begin());
    cout << "Backup Created" << endl << "Backup Data: ";
    for(auto v:backup_data)
    {
        cout << v << " ";
    }
    cout << endl;

    cout << "---- Transform ----" << endl;
    vector<float> speeds(10);
    for(auto& v:speeds)
    {
        v = data();
    }
    cout << "Speeds in Kmph: ";
    for(auto v:speeds)
    {
        cout << v << " ";
    }
    transform(speeds.begin(),speeds.end(),speeds.begin(),[](int x){return x* 0.621371;});
    cout << endl << "Speeds in mph: ";
    for(auto v:speeds)
    {
        cout << v << " ";
    }
    cout << endl;

    cout << "---- Replace ---- " << endl;
    vector<int> sensor_temp(5);
    cout << "Sensor readings: ";
    for(int i=0;i<4;i++)
    {
        sensor_temp[i] = data();
        cout << sensor_temp[i] << " ";
    }
    sensor_temp[4] = -1;
    cout << sensor_temp[4] << endl;

    replace(sensor_temp.begin(),sensor_temp.end(),-1,90);
    cout << "sensor reading after replacing:" ;
    for_each(sensor_temp.begin(),sensor_temp.end(),[](int x){cout << x << " "; });

    cout << "Merge" << endl;
    vector<int> measurements1;
    for(int i=0;i<10;i++)
    {
        measurements1.push_back(rand()%100);
    }
    vector<int> measurements2;
    for(int i=0;i<10;i++)
    {
        measurements2.push_back(rand()%100);
    }
    cout << "measurements1: ";
    for_each(measurements1.begin(),measurements1.end(),[](int x){cout << x << " ";});
    cout << endl << "measurements2: ";
    for_each(measurements2.begin(),measurements2.end(),[](int x){cout << x << " ";});
    cout << endl;
    vector<int> measurements3(20);
    merge(measurements1.begin(),measurements1.end(),measurements2.begin(),measurements2.end(),measurements3.begin());
    sort(measurements3.begin(),measurements3.end());
    cout << "measurements3: ";
    for_each(measurements3.begin(),measurements3.end(),[](int x){cout << x << " ";});
    cout << endl;

    cout <<"---- Partition ----" << endl;
    vector<pair<string,string>> vehicles;
    for(int i=0;i<7;i++)
    {
        string car,type;
        cout << "Enter the car name and fuel: ";
        cin >> car >> type;
        vehicles.push_back({car,type});
    }

    for_each(vehicles.begin(),vehicles.end(),[](const pair<string,string> v){cout << v.first << " : " << v.second << " ";});
    cout << endl;
    stable_partition(vehicles.begin(),vehicles.end(),[](const pair<string,string> v){return v.second == "Electric";});

   for_each(vehicles.begin(),vehicles.end(),[](const pair<string,string> v){cout << v.first << " : " << v.second << " ";});
}