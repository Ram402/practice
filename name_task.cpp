#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX_SPEED_KMPH 200
#define DEBUG_MODE

using namespace std;

namespace VehicleECU
{
    namespace SpeedModule
    {
        float speed;
    } // namespace SpeedModule
    namespace Diagnostics
    {
        void diagnose(string name,int speed)
        {
            fstream file(name,ios::out | ios::app);
            if(!(file))
            {
                cout << "File is not existed" << endl;
                return;
            }
            if (speed > MAX_SPEED_KMPH)
            {
                file << "[logs] speed: " << speed << " kmph " << "Speed Limit Exceeded : Overspeed Warning Initiated " << endl;
            }
            else
            {
                file << "[logs] speed: " << speed << " kmph " << "Speed Limit Normal " << endl;
            }
        }
    }
}


inline float kmphToMps(float kmph)
{
    return kmph * 0.27778;
}

class SpeedLimiter
{
    int Limit;
    public:
    SpeedLimiter(int Limit) : Limit(Limit){}
    void operator()(int speed)
    {
        if (speed > Limit)
        {
            cout << "Speed Limit Exceeded: Applying Brake Boost" << endl;
        }
        else
        {
            cout << "Speed Limit Normal" << endl;
        }
         
    }
};


int main(int arg_c,char * arg_v[])
{
    int speed;
    cout << "Enter the speed(kmph): ";
    cin >> speed;
    const type_info& t1 = typeid(speed);
//     VehicleECU::SpeedModule::speed = static_cast<float>(speed);
//     VehicleECU::SpeedModule::speed = kmphToMps(VehicleECU::SpeedModule::speed);
//     SpeedLimiter(MAX_SPEED_KMPH)(speed);
//     VehicleECU::Diagnostics::diagnose(arg_v[1],speed);
// #ifdef DEBUG_MODE
//         cout << "Diagnostics: speed = " << setprecision(3) << VehicleECU::SpeedModule::speed << " mps" << endl;
// #endif 
cout << t1.name() << endl;
}

