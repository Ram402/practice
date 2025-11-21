#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <map>
#include <thread>
#include <vector>
#include <memory>
#include <mutex>
#include <chrono>
using namespace std;
mutex mtx;
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
    int  ac;
    int  recirculation;
    int  AUTO_mode;
    vector<thread> background_task;
    public:
    TempUnit unit;
    public:
    HVAC(float target_temp,float curr_temp,int fan_speed,map<string,string> airFlow,int ac,int recirculation,int AUTO_mode,TempUnit unit): 
            target_temp(target_temp),curr_temp(curr_temp),fan_speed(fan_speed),airFlow(airFlow),ac(ac),recirculation(recirculation),AUTO_mode(AUTO_mode),unit(unit){}
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

    void save_settings(const string filename)
    {
        fstream file(filename,ios::out );
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


    void save_to_file(string filename,vector<HVAC*> logs)
    {
        fstream file(filename,ios::out);
        if(!(file))
        {
            cout << "File failed to open" << endl;
            return;
        }
        map<string,string> temp;
        for(auto& p:logs)
        {
            file << "HVAC Status" << endl;
            file << "Target Temperature: " << p->get_target_temp() << endl << 
                    "Current Temperatue: " << p->get_current_temp() << endl <<
                    "Fan Speed: " << p->get_fanspeed() << endl;
            temp = p->get_airflow();
            for(auto& p: airFlow)
            {
                if (p.second == "NULL")
                    file << "AirFlow mode: " << p.first << endl;
                else
                    file << "AirFlow mode: " << p.first << "+" << p.second << endl;
            }
            if (p->get_ac())
                file << "AC status: ON" << endl;
            else   
                file << "AC status: OFF" << endl;

            if (p->get_recirculation())
                file << "Recirculation: ON" << endl;
            else   
                file << "Recirculation OFF" << endl;
            if (p->get_mode())
                file << "AUTO Mode: ENABLED" << endl;
            else   
                file << "AUTO Mode: DISABLED" << endl;
        }
    }

    void start_running(HVAC& object,vector<HVAC*>& logs)
    {
        background_task.emplace_back([this,&object,&logs](){
            float temp;
            if ( object.get_temp_unit() == 0)
                temp = 16 + static_cast<float>(rand())/ (static_cast<float>(RAND_MAX)/(16+30));
            else
                temp = 60 + static_cast<float>(rand())/ (static_cast<float>(RAND_MAX)/(60+86));
            
            TempUnit temperary;
            if (object.get_temp_unit() == 0)
            {
                temperary = TempUnit::Celsuis;
            }
            else
                temperary = TempUnit::Fahrenheit;

            HVAC * new_object = new HVAC(object.get_target_temp(),temp,object.get_fanspeed(),object.get_airflow(),object.get_ac(),object.get_recirculation(),object.get_mode(),temperary);
            {
                lock_guard<mutex> lock(mtx);
                logs.push_back(new_object);
            }
            this_thread::sleep_for(chrono::seconds(1));
        });
    }

    float get_current_temp()
    {
        return curr_temp;
    }

    float get_target_temp()
    {
        return target_temp;
    }

    int get_fanspeed()
    {
        return fan_speed;
    }

    map<string,string> get_airflow()
    {
        return airFlow;
    }
    int get_temp_unit()
    {
        if (unit == TempUnit::Celsuis)
            return 0;
        else
            return 1;
    }
    int get_ac(){ return ac; }
    int get_recirculation() { return recirculation; }
    int get_mode(){ return AUTO_mode; }
};


int main()
{
    HVAC settings,temp;
    vector<HVAC*> logs;
    temp.start_running(settings,logs);
    int option;
    while(1)
    {
            cout << "1. Set Temperature\n2. Set Fan Speed\n3. Chnage Airflow Mode\n4. Toggle AC\n5. Toggle Recirculation\n6. Enable\\Disable AUTO Mode\n7. Change Temperature Unit (C <-> F) <--- NEW\n8. Show Current Status\n9.Exit\n\n Choose> ";
            cin >> option;
            switch (option)
            {
            case 1:
                settings.set_temperature();
                break;
            case 2:
                settings.set_Fan_speed();
                break;
            case 3:
                settings.Chnage_Airflow();
                break;
            case 4:
                settings.Toggle_AC();
                break;
            case 5:
                settings.Toggle_recirculation();
                break;
            case 6:
                settings.Enable_Disable_AUTO();
                break;
            case 7:
                settings.Change_temp_unit();
                break;
            case 8:
                // settings.show_current_status();
                break;
            case 9:
            settings.save_settings("havc_settings.cfg");
                return 0;
            default:
                break;
            }
    } 
    return 0;
}
