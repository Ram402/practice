#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class vehicleECU
{
    private:
    int ecuId;
    string vehicleModel;
    static int ecuCount;
    const string manufacturer = "Bosch";
    public:
    vehicleECU(int ecuid,string model): ecuId(ecuid),vehicleModel(model){ecuCount++;}
    ~vehicleECU(){}

    virtual void diagnose() = 0;
    friend void display_ECUdata(vehicleECU& obj);
};

int vehicleECU :: ecuCount = 0;

void display_ECUdata(vehicleECU& obj)
{
    cout << "---- ECU data ----" << endl;
    cout << "ECU ID: " << obj.ecuId << endl;
    cout << "Vehicle Model: " << obj.vehicleModel << endl;
    cout << "Manufacturer: " << obj.manufacturer << endl;
    cout << "ECU count: " << obj.ecuCount << endl;
}

class EngineECU : public vehicleECU
{
    volatile int rpm;
    float temperature;

    public:
    EngineECU(int rpm,float temp): rpm(rpm),temperature(temp),vehicleECU(1,"Audi") {}

    void diagnose()
    {
        if (temperature > 100 )
            cout << "Temp: " << temperature << " Warning High Temperature" << endl;
        else
            cout << "Temp: " << temperature << " Normal" << endl;
    }
};

template <typename T>
class Sensor
{
    string name;
    T value;
    public:
    Sensor(string name,T value): name(name),value(value){}

    T get_value()
    {
        return value;
    }

    void update_vaue(T v)
    { 
        if (v < 0)
        { 
           throw invalid_argument("if ");
        }
    }

};

void rpm_data(Sensor<int>& rpms)
{
    rpms.update_vaue(rand()%100);
    this_thread::sleep_for(chrono::milliseconds(100));
}

void temp_data(Sensor<float>& temps)
{
    temps.update_vaue(rand()%100 * 0.01);
    this_thread::sleep_for(chrono::milliseconds(100));
}


int main()
{
    // vector<shared_ptr<Sensor<int>>> sensor_data;
    EngineECU engineobj(0,0);
    display_ECUdata(engineobj);

    Sensor<int> rpmSensor("RPM",0);
    Sensor<float> tempSensor("Temp",0);

    thread rpm(rpm_data,ref(rpmSensor));
    thread temp(temp_data,ref(tempSensor));

}