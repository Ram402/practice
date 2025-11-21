#include <iostream>
#include <array>
#include <string>
 
using namespace std;
 
class ECU_sensor
{
    private:
    float temperature;
    int rpm;
    int sensorId;
    static int Sensor_count;
    const string sensortype;
    public:
    ECU_sensor(float temp,int rpm,int sensorId,const string sen_type):
        temperature(temp),rpm(rpm),sensorId(sensorId),sensortype(sen_type) {
            cout << "Sensor Added" << endl;
        }
 
    ~ECU_sensor() {
        cout << "Sensor Removed" << endl;
    }
 
    float get_temp()
    {
        return temperature;
    }
 
    int get_rpm()
    {
        return rpm;
    }
 
    int get_sensor_id()
    {
        return sensorId;
    }
 
    int get_sencnt()
    {
        return Sensor_count;
    }
 
    string get_sentype()
    {
        return sensortype;
    }

    friend class CalibrationUnit;
    friend void update_sensor_count(ECU_sensor& obj);
    friend void show_sensor_Details(ECU_sensor& obj);
};

int ECU_sensor:: Sensor_count = 0;

class CalibrationUnit
{
    public:
    void update_features(ECU_sensor& obj)
    {
        cout << "Enter the tuned temperature: ";
        cin >> obj.temperature;
        cout << "Enter the tuned rpm: ";
        cin >> obj.rpm;
    }
};

void Add_Sensor(array<ECU_sensor* ,20>& V,int * size); 
void display_Sensor(array<ECU_sensor* ,20> V,int size);
void calibrate_data(array<ECU_sensor* ,20>& V,int size);
void display_sensor_count(array<ECU_sensor* ,20> V,int size);

void update_sensor_count(ECU_sensor& obj)
{
    obj.Sensor_count++;
}
void show_sensor_Details(ECU_sensor& obj)
{
    // cout << "Sensor Details" << endl;
    cout << "Sensor Id: " << obj.sensorId << endl;
    cout << "Temperature: " << obj.temperature << endl;
    cout << "RPM: " << obj.rpm << endl;
    cout << "Sensor Type: " << obj.sensortype << endl;
    cout << "Sensor Count: " << obj.Sensor_count << endl;
}
 
int main()
{
    array<ECU_sensor * ,20> data;
    cout << "ECU sensor Monitor System"  << endl;
    int size = 0,choice;
    while(true)
    {
        cout << "1.Add ECU Sensor" << endl << "2.Show Senso Details" << endl << "3.Calibrate Sensor" << endl << "4.Display Total Sensor Count" << endl << "5.Simulate Live RPM Update" << endl << " 6.Exit" << endl << endl;
        cout << "\nEnter the option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                if (size == 20)
                {
                    cout << "Vehicle DataBase is full" << endl;
                }
                else
                {
                    Add_Sensor(data , &size);
                }
                cout << endl;
            }
            break;
        case 2:
            {
                display_Sensor(data,size);
                cout << endl;
            }
            break;
        case 3:
            {
                calibrate_data(data,size);
            }
            break;
        case 4:
                display_sensor_count(data,size);
            break;
        case 5:
            break;
        case 6:
            for(int i=0;i<size;i++) delete data[i];
            exit(0);
        default:
            break;
        }
    }
}
 
void Add_Sensor(array<ECU_sensor* ,20>& V,int * size)
{
    float temperature;
    int rpm,sensorId;
    string sensortype;
    cout << "Enter the sensor Id: ";
    cin >> sensorId;
    cout << "Enter the temperature: ";
    cin >> temperature;
    cout << "Enter the rpm: ";
    cin >> rpm;
    cout << "Enter the sensor type: ";
    cin >> sensortype;
    V[(*size)++] = new ECU_sensor(temperature,rpm,sensorId,sensortype);
    update_sensor_count(*(V[(*size)]));
}

void display_Sensor(array<ECU_sensor* ,20> V,int size)
{
    cout << " --- sensor Details --- " << endl;
    for(int i=0;i<size;i++)
    {
        show_sensor_Details(*(V[i]));
        cout << endl;
    }
}

void calibrate_data(array<ECU_sensor* ,20>& V,int size)
{
    int id,flag = 0;
    cout << "Enter the sensor id to calibrate: ";
    cin >> id;
    for(int i=0;i<size;i++)
    {
        if(id == (V[i])->get_sensor_id())
        {
            cout << "Sensor Id found" << endl;
            CalibrationUnit obj;
            obj.update_features(*(V[i]));
            flag = 1;
        }
    }
    if(flag == 0)
    {
        cout << "Sensor Id not found" << endl;
    }
}

void display_sensor_count(array<ECU_sensor* ,20> V,int size)
{
    cout << "Sensor count:" << (*(V[(size-1)])).get_sencnt() << endl << endl;
}