#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
using namespace std;

class VehicleECU
{
    int ecuID;
    string vehicleModel;
    public:
    VehicleECU(int id,string model) : ecuID(id),vehicleModel(model) {}
    virtual void diagnose() = 0;
};

class EngineECU : public VehicleECU
{
    volatile int rpm;
    volatile float temp;
    public:
    EngineECU(volatile int RPM,volatile int Temp): rpm(RPM),temp(Temp),VehicleECU(1,"Bosch") {}

    void diagnose() override
    {
        if (rpm > 220)
            cout  << "RPM is unstable, Critical Warning" << endl;
        else
            cout << "RPM is stable, No problem" << endl;
        if (temp > 100)
            cout  << "Temp is unstable, Critical Warning Initiated" << endl;
        else
            cout << "Temp is stable, No Problem" << endl; 
    }
};


template <typename T>
class Sensor
{
    string name;
    T value;
    public:
    Sesnor() {}
    
    string get_name() {return name;}
    T get_value() { return value;}
    void set_value(T val) { value = val;}
};

int main()
{
    // vector<shared_ptr<Sensor>> objects = make_shared<int>;
}
