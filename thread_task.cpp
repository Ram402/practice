#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <fstream>


using namespace std;

int engineTemp;
bool data_ready = false;
bool actuator_flag = false;
int actuator_mode;
mutex mtx1,mtx2,print_mtx1,print_mtx2,print_mtx3;
condition_variable cv1;
condition_variable cv2;

void temp(fstream&file);
void engine(fstream& file);
void actuator(fstream& file);
int produce_data();
void delay(int n);

int main(int argc,char * argv[])
{

    fstream  file(argv[1],ios::out | ios::app);
    try
    {
      if (!file)
        throw runtime_error("File is not sending");
    }
    catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
        return 0;
    }  
    thread task1(temp,ref(file));
    thread task2(engine,ref(file));
    thread task3(actuator,ref(file));

    task1.join();
    task2.join();
    task3.join();

    file.close();
}

int produce_data()
{
    int random = 80 + (rand() % (110 - 80 + 1));  // random between 80 and 110
    return random;
}

void delay(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
}

void temp(fstream& file)
{
    int i = 0;
    while(i < 10)
    {
        delay(5);
        mtx1.lock();
        engineTemp = produce_data();
        data_ready = true;
        {
            file << "[sensor] Engine Temperature: " << engineTemp << endl;
            cout << "[sensor] Engine Temperature: " << engineTemp << endl;
        }
        mtx1.unlock();
        i++;
        cv1.notify_all();
    }
}

void engine(fstream& file)
{
    int i=0;
    while(i<10)
    {
        {
            unique_lock<mutex> lock(mtx1);
            cv1.wait(lock,[] {return data_ready;});
            actuator_flag = true;
            if (engineTemp > 100)
            {
                actuator_mode = 1;
                cout << "[Engine] temperature is High" << endl;
                file << "[Engine] temperature is High" << endl;
            }
            else if (engineTemp < 90)
            {
                actuator_mode = 0;
                cout << "[Engine] Temperature is Low" << endl;
                file << "[Engine] Temperature is Low" << endl;
            }
            else
            {
                actuator_mode = -1;
                cout << "[Engine] Temperature is Normal" << endl;
                file << "[Engine] Temperature is Normal" << endl;
            }
            i++;
            data_ready = false;
        }
        cv2.notify_all();
    }
}

void actuator(fstream& file)
{
    int i=0;
    while(i<10)
    {
        unique_lock<mutex> lock(mtx2);
        cv2.wait(lock,[] {return actuator_flag;});
        if (actuator_mode == 1)
        {
            cout << "[Actuator] Cooling system turned ON" << endl;
            file << "[Actuator] Cooling system turned ON" << endl;
        }
        else if (actuator_mode == 0)
        {
            cout  << "[Actuator] Cooling system turned OFF" <<  endl;
            file << "[Actuator] Cooling system turned OFF" <<  endl;
        }
        else
        {
            cout  << "[Actuator] No change in the Cooling System" <<  endl;
            file << "[Actuator] No change in the Cooling System" <<  endl;
        }
        i++;
        actuator_flag =false;
    }
}