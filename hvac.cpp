#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <map>
#include <thread>
#include <vector>
#include <tuple>
#include <memory>

using namespace std;

enum class TempUnit
{
    Celsuis,
    Fahrenheit
};

class HVAC
{
    private:
    // tuple<float,float,float> temp;
    float curr_temp;
    float target_temp;
    // float ambient_temp;
    int fan_speed;
    map<string,string> airFlow;
    bool ac;
    bool recirculation;
    bool AUTO_mode;
    TempUnit unit;
    vector<thread> background_task;
    vector<unique_ptr<HVAC>> logs;
    public:
    HVAC(){}

    void set_temperature()
    {
        // float temperature;
        cout << "Enter the target Temperature: ";
        cin >> curr_temp;
        // temp.insert({0.0,temperature,0.0});
    }

    void set_Fan_speed()
    {
        cout << "Enter the target Fan speed(0-7): ";
        cin >> fan_speed;
    }

    void Chnage_Airflow()
    {
        int option;
        cout << "Enter the Air flow mode(0: FACE,1: FEET,2: DEFOREST,3: FACE+FOREST,4: FEET+DESFOREST): ";
        cin >> option;
        switch(option)
        {
            case 0:
                airFlow.insert({"FACE","NULL"});
                break;
            case 1:
                airFlow.insert({"FEET","NULL"});
                break;
            case 2:
                airFlow.insert({"DEFOREST","NULL"});
                recirculation = 0;
                break;
            case 3:
                airFlow.insert({"FACE","FEET"});
                recirculation = 0;
                break;
            case 4:
                airFlow.insert({"FEET","DEFOREST"});
                recirculation = 0;
                break;
            default:
                break;
        }
    }

    void Toggle_AC()
    {
        ac = !(ac);
    } 

    void Toggle_recirculation()
    {
        recirculation = !(recirculation);
    }

    void Enable_Disable_AUTO()
    {
        cout << "Enter AUTO mode (0:Enable, 1:Disable): ";
        cin >> AUTO_mode;
    }

    void Change_temp_unit()
    {
        bool units;
        cout << "Enter unit of Temperature(0: C, 1: F): ";
        cin >> units;
        if (units == 1)
            unit = TempUnit::Fahrenheit;
        else
            unit = TempUnit::Celsuis;
    }

    void show_current_status()
    {
        
    }

    void save_settings(const string filename)
    {
        fstream file(filename,ios::in | ios::out );
        if (!(file))
        {
            cout << "File failed to Open" << endl;
            exit(1);
        }
        file << "User Settings" << endl;
        // for(auto& p: temp)
        // {
        //     file << "Target Temperature: " << p.second << endl;
        // }
        file << "Target Temperature: " << target_temp;
        if (unit == TempUnit::Celsuis)
            file << "C" << endl;
        else
            file << "F" << endl;
        file << "Target Fan speed: Level " << fan_speed << endl;
        for(auto&p : airFlow)
        {
            file << "Air Flow: " << p.first;
            if (p.second != "NULL")
                file << " ," << p.second;
        }
        file << endl << "AC status: " << ac << endl;
        file << "Recirculation: " << recirculation << endl;
        if (AUTO_mode == 0)
            file << "AUTO Mode: ENABLED" << endl;
        else
            file << "AUTO Mode: DISABLED" << endl;
        
        if (unit == TempUnit::Celsuis)
            file << "Temperature Unit: Celsuis" << endl;
        else
            file << "Temperature Unit: Fahrenheit" << endl;

        file.close();
    }

    void start_running(HVAC object)
    {
        background_task.emplace_back([this,&object](){
            if (object.get_unit() == TempUnit::Celsuis)
                float temp = 16 + static_cast<float>(rand())/ (static_cast<float>(RAND_MAX)/(16+30));
            else
            float temp = 60 + static_cast<float>(rand())/ (static_cast<float>(RAND_MAX)/(60+86));

        
        });
    }

    float get_target_temp()
    {
        return target_temp;
    }

    int get_fanspeed()
    {
        return fan_speed;
    }

    // map get_airflow()
    // {
    //     return airFlow;
    // }

    bool get_ac(){ return ac; }
    bool get_recirculation() { return recirculation; }
    bool get_mode(){ return AUTO_mode; }
    inline TempUnit get_unit() { return unit; }
};


int main()
{
    // HVAC settings;
    // int option;
    // while(1)
    // {
    //         cout << "1. Set Temperature\n2. Set Fan Speed\n3. Chnage Airflow Mode\n4. Toggle AC\n5. Toggle Recirculation\n6. Enable\\Disable AUTO Mode\n7. Change Temperature Unit (C <-> F) <--- NEW\n8. Show Current Status\n9.Exit\n\n Choose> ";
    //         cin >> option;
    //         switch (option)
    //         {
    //         case 1:
    //             settings.set_temperature();
    //             break;
    //         case 2:
    //             settings.set_Fan_speed();
    //             break;
    //         case 3:
    //             settings.Chnage_Airflow();
    //             break;
    //         case 4:
    //             settings.Toggle_AC();
    //             break;
    //         case 5:
    //             settings.Toggle_recirculation();
    //             break;
    //         case 6:
    //             settings.Enable_Disable_AUTO();
    //             break;
    //         case 7:
    //             settings.Change_temp_unit();
    //             break;
    //         case 8:
    //             settings.show_current_status();
    //             break;
    //         case 9:
    //         settings.save_settings("havc_settings.cfg");
    //             return 0;
    //         default:
    //             break;
    //         }
    // } 
    return 0;
}
