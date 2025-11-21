#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <chrono>
#include <string>
#include <fstream>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

#define FILE_NAME "bcm_log.txt"
#define refresh_delay 3

mutex mtx;
condition_variable cv;
bool headlight_ready = false,Doorlock_ready = false,Wiper_ready = false;

namespace BCM
{
    class VehicleComponent
    {
        string name;
        bool status;
        public:
        VehicleComponent(string name,bool status) : name(name),status(status){}
        
        void activate()
        {
            status = !(status);
        }

        string get_name()
        {
            return name;
        }
        bool get_state()
        {
            return status;
        }

        virtual void activation() = 0;
        virtual void display() = 0;
    };

    class HeadLight :public VehicleComponent
    {
        public:
        HeadLight(): VehicleComponent("Head Light",1){}

        void activation()
        {
            activate();
        }

        void  display()
        {
            cout << get_name() <<  " -> " << (get_state()?"ON" : "OFF") << endl;   
        }

    };

    class DoorLock :public VehicleComponent
    {
        public:
        DoorLock(): VehicleComponent("Door Lock",0){}

        void activation()
        {
            activate();
        }

        void  display()
        {
            cout << get_name() <<  " -> " << (get_state()?"LOCKED" : "UNLOCKED") << endl;   

        }
    };

    class Wiper :public VehicleComponent
    {
        public:
        Wiper(): VehicleComponent("Wiper",0){}

        void activation()
        {
            activate();
        }

        void  display()
        {
            cout << get_name() <<  " -> " << (get_state()?"ON" : "OFF") << endl;   

        }
    };
}

void Headlight(vector<unique_ptr<BCM::VehicleComponent>>& obj);
void Doorlock(vector<unique_ptr<BCM::VehicleComponent>>& obj);
void Wiper(vector<unique_ptr<BCM::VehicleComponent>>& obj);
void logger(vector<unique_ptr<BCM::VehicleComponent>>& obj);


// time format not working 
inline string current_time()
{
    ostringstream oss;
    auto current_time = chrono::high_resolution_clock::now();
    time_t now = time(0);
    tm local_tm;
    localtime_s(&local_tm,&now);
    oss << put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << endl;
    return oss.str();
}

class Logging
{
    public:
    void operator()(vector<unique_ptr<BCM::VehicleComponent>>& obj)
    {
        for_each(obj.begin(),obj.end(),[](auto& object){
            if (object.get_state() == 0)
                cout << object.get_name();
                cout << " ";
        });
    }
};



int main()
{
    fstream create_fs(FILE_NAME,ios::out | ios::app);
    create_fs.close();
    ifstream file(FILE_NAME);
    if (!(file))
    {
        cout << FILE_NAME <<" file does not exist" << endl;
        return 1;
    }
    string line;
    bool flag = false;
    cout << "[INFO] ";
    while(getline(file,line))
    {
        flag = true;
        cout << line << endl;
    }
    if (flag == false)
    cout << " No previous log found (bcm_log.txt)." << endl << endl;
    file.close();
    //starting the system
    cout << "[IGNITION] Press Enter to start BCM system..." << endl;
    getchar(); 

    vector<unique_ptr<BCM::VehicleComponent>> objects;
    objects.push_back(make_unique<BCM::HeadLight>());
    objects.push_back(make_unique<BCM::DoorLock>());
    objects.push_back(make_unique<BCM::Wiper>());
    char control;
    bool exit_flag = false;
    thread controls([&control]() {
        cin >> control;
    });
    while(exit_flag == false)
    {
        thread headlight(Headlight,ref(objects));
        thread doorlock(Doorlock,ref(objects));
        thread wiper(Wiper,ref(objects));
        thread logging(logger,objects);
        headlight.join();
        doorlock.join();
        wiper.join();
        logging.join();
        cout << "Press ctrl + 'c' to quit" << endl << endl;
        // if (control == 'q' || control == '\n')
        // {
        //     exit_flag = true;
        // }
        this_thread::sleep_for(chrono::seconds(refresh_delay));
    }
    controls.join();
    return 0;
}


void Headlight(vector<unique_ptr<BCM::VehicleComponent>>& obj)
{
    {
        lock_guard<mutex> lock(mtx);
        obj[0]->activation();
        headlight_ready = true;
    }
    cv.notify_all();
}

void Doorlock(vector<unique_ptr<BCM::VehicleComponent>>& obj)
{
    {
        lock_guard<mutex> lock(mtx);
        obj[1]->activation();
        Doorlock_ready = true;
    }
    cv.notify_all();
}

void Wiper(vector<unique_ptr<BCM::VehicleComponent>>& obj)
{
    {
        lock_guard<mutex> lock(mtx);
        obj[2]->activation();
        Wiper_ready = true;
    }
    cv.notify_all();
}

void logger(vector<unique_ptr<BCM::VehicleComponent>>& obj)
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock,[](){return headlight_ready && Doorlock_ready && Wiper_ready;});
    cout << "========== BCM STATUS ==========" << endl;
    ofstream file(FILE_NAME,ios::app);
    if (!(file))
    {
        cout << FILE_NAME << " file doesnot exist" << endl;
    }
    int count=0;
    for_each(obj.begin(),obj.end(),[&file,&count](auto& object){
        cout << "[INFO] ";
        object->display();
        count++;
       if (count == 2)
            file << "[" << current_time() << "]" << "[INFO] " << object->get_name() <<  " -> " << (object->get_state()?"ON" : "OFF") << endl; 
        else
            file << "[" << current_time() << "]" << "[INFO] " << object->get_name() <<  " -> " << (object->get_state()?"LOCKED" : "UNLOCKED") << endl; 
    });
    int counter = count_if(obj.begin(),obj.end(),[](auto& object){return object->get_state() == 1;});
    cout << "-----------------------------------" << endl;
    cout << "Active components: " << counter << endl;
    file.close();

    if (counter != 3)
    {
        cout << "[WARN] Some Components are not Active: ";
        // Logging()(obj);
        cout << endl;
    }
}