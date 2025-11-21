#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <condition_variable>
using namespace std;

template <typename T>
class Sensor {
    string name;
    T value;
    static int sensor_cnt;

public:
    Sensor(string name) : name(name) {
        value = 0;
        sensor_cnt++;
    }

    T get_value() { return value; }

    void set_value(T v) { value = v; }

    void display_data() { cout << name << " : " << value << endl; }
};

template <typename T>
int Sensor<T>::sensor_cnt = 0;

mutex mtx;
condition_variable cv;
bool rpm_turn = true; // true => rpm prints first

int main() {
    Sensor<int> rpmSensor("RPM");
    Sensor<float> tempSensor("Temp");

    thread rpm([&]() {
        while (1) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [] { return rpm_turn; }); // wait until it's rpm's turn

            rpmSensor.set_value(rand() % 100);
            rpmSensor.display_data();

            rpm_turn = false; // now temp's turn
            lock.unlock();
            cv.notify_all();

            this_thread::sleep_for(chrono::seconds(1));
        }
    });

    thread temp([&]() {
        while (1) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [] { return !rpm_turn; }); // wait until it's temp's turn

            tempSensor.set_value((rand() % 10) * 0.1);
            tempSensor.display_data();

            rpm_turn = true; // now rpm's turn
            lock.unlock();
            cv.notify_all();

            this_thread::sleep_for(chrono::seconds(1));
        }
    });

    rpm.join();
    temp.join();
}
