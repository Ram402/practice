#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
int min = 35 , max = 110 , mode;
double temp;
std::condition_variable cv1,cv2;
int task;
std::mutex mtx ,mtx1;
 
void Sensor()
{
    int i=10;
    while(i--)
    {
        {
            std::lock_guard<std::mutex> lock(mtx);
            temp = min+rand() % (max - min + 1);
            {
                std::lock_guard<std::mutex> lock(mtx1);
                task = 1;
            }
            cv1.notify_one();
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
 
void Ecu()
{
    int i=10;
    while(i--)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv1.wait(lock, [](){return (task==1) ? true : false;});
        cv2.notify_one();
         {
                std::lock_guard<std::mutex> lock(mtx1);
                task = 2;
        }
 
        mode = (temp > 100) ? 1 : (temp < 45) ? 2 : 0;
    }
}
 
void Actuator()
{
    int i=10;
    std::cout<<std::endl;
    while(i--)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv2.wait(lock,[](){return (task==2) ? true : false;});
        if(mode == 1)
            std::cout<<"Temp : "<<temp<<" , Temprature is more than 100 Turning ON the Cooling system."<<std::endl;
        else if(mode==2)
            std::cout<<"Temp : "<<temp<<" , Temprature is less than 45 Turning OFF the Cooling system."<<std::endl;
        else
            std::cout<<"Temp : "<<temp<<" , Temprature is steady No change in cooling system."<<std::endl;
        {
            std::lock_guard<std::mutex> lock(mtx1);
            task = 0;
        }
        std::cout<<std::endl;
    }
 
}
 
int main()
{
    std::thread t1,t2,t3;
 
    t1 = std::thread(Sensor);
    t2 = std::thread(Ecu);
    t3 = std::thread(Actuator);
 
    t1.join();
    t2.join();
    t3.join();
}