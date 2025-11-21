#include <iostream>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include <sstream>
#include <fstream>
#include <chrono>
#include <iomanip>
using namespace std;

class Sensor
{
    protected:
        string sensor_type;
    public:
        Sensor(string type): sensor_type(type){}
        virtual ~Sensor(){}

        float generate_data()
        {
            return 0.0 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (50.0 - 0.0)); 
        }
        
        virtual string get_data() = 0;
};

class CameraSensor : public Sensor
{
    private:
        float x,y,z;
    public:
        CameraSensor(string sensor_name): Sensor(sensor_name){}

    string get_data()
    {
        x = generate_data();
        y = generate_data();
        z = generate_data();
        ostringstream oss;
        oss << "Camera,\"[" << setprecision(3) << x << "," << y << "," << z << "]\"";
        return oss.str();
    }
};

class RadarSensor : public Sensor
{
    private:
        float x,y,z;
    public:
        RadarSensor(string sensor_name): Sensor(sensor_name){}

    string get_data()
    {
        x = generate_data();
        y = generate_data();
        z = generate_data();
        ostringstream oss;
        oss << "Radar,\"[" << setprecision(3) << x << "," << y << "," << z << "]\"";
        return oss.str();
    }
};


class DataLogger
{
    private:
    vector<string> logs;
    size_t log_count;

    public:
    DataLogger(){log_count =0;}
    void logData(const std::string& data)
    {
        ostringstream oss;
        oss << get_current_time() << "," << data;
        logs.push_back(oss.str());
        log_count++;
    }

    string get_current_time()
    {
        ostringstream oss;
        time_t now = time(0);
        tm local_t;
        localtime_s(&local_t,&now);
        oss << put_time(&local_t,"%H:%M:%S");
        return oss.str();
    }

    void saveToFile(const std::string& filename)
    {
        ofstream file(filename);
        if (!(file))
        {
            cout << "File opening failed" << endl;
            exit(1);
        }
        file << "TIMESTAMP,SENSOR TYPE,RAWDATA" << endl;
        for(auto& d: logs)
        {
            file << d << endl;
        }
    }
    
    size_t getLogCount() const
    {
        return log_count;
    }
};

class SensorManager
{
    private:
        mutex mtx;
        vector<unique_ptr<Sensor>> sensors;
        unique_ptr<DataLogger> logger;
        vector<thread> threads;

    public:

    void add_sensor(unique_ptr<Sensor> sensor)
    {
        sensors.push_back(move(sensor));
    }

    void start_logging(int duration)
    {
        logger = make_unique<DataLogger>();
        cout << "Starting ADAS sensor logger" << endl;
        cout << "Logging for " << duration << "seconds" << endl;
        for (auto& sensor : sensors)
        {
            threads.push_back(std::thread([this, &sensor, duration]() {

                int totalLogs = duration * 2;   // 5 sec → 10 logs

                for (int i = 0; i < totalLogs; i++)
                {
                    this_thread::sleep_for(std::chrono::milliseconds(500));

                    string data = sensor->get_data();

                    {
                        lock_guard<mutex> lock(mtx);
                        logger->logData(data);
                    }
                }

            }));
        }


        for(auto& i: threads)
        {
            if (i.joinable())
                i.join();
        }
    }

    DataLogger* get_logger()
    {
        return logger.get();
    }
};


int main()
{
    srand(time(NULL));
    // DataLogger log_data;
    SensorManager manager;
    manager.add_sensor(make_unique<CameraSensor>("CAMERA"));
    manager.add_sensor(make_unique<RadarSensor>("RADAR"));

    manager.start_logging(5);
    DataLogger* log = manager.get_logger();
    log->saveToFile("Adas_data.csv");

    cout << "Total Logs: " << log->getLogCount() << endl;
    // time_t now = time(0);
    // cout << now << endl;
}