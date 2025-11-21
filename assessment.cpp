#include <iostream>
#include <fstream>
#include <exception>
#include <memory>

using namespace std;
static int ele_count;
constexpr float MIN_TEMP = 18.0f;
constexpr float MAX_TEMP = 28.0f;
constexpr float MAX_FAN_SPEED = 10;


class cust_exception : public exception
{
    public:  
    cust_exception(exception& e)
    {
        cout << "Exception Caught" << e.what() << endl;
    }
};

template <typename t>  
class ClimateElement
{
  private:
  string name;
  t value;
  string unit;
  public:
  ClimateElement(string name,string unit) : name(name),unit(unit){}

  void set_value(t v)
  {
    value = v;
  }

  t get_value()
  {
    return value;
  }

  virtual void display_info() = 0;
  virtual void updateValue(t newValue) = 0;

};



class TemperatureControl : public ClimateElement<float>
{
    public:
    TemperatureControl() : ClimateElement("Temp","C"){}
    void display_info() override
    {
        cout << "Temperature: " << get_value() << " C"; 
        if ((get_value() > MAX_TEMP) || (get_value() < MIN_TEMP))
        {
            cout << " High Temperature Warning";
        }
        cout << endl;
    }

    void updateValue(float v) override
    {
        set_value(v); 
    }
};

class FanControl : public ClimateElement<int>
{
    public:
    FanControl() : ClimateElement("Fan","rpm") {}

    void display_info() override
    {
        cout << "Fan Speed: " << get_value();
        if (get_value() > MAX_FAN_SPEED)
        {
            cout << " Fan Speed too high";
        }
        cout <<  endl;
    }

    void updateValue(int v) override
    {
        set_value(v); 
    }
};

class ModeControl : public ClimateElement<int>
{
    public:
    ModeControl() : ClimateElement("Mode",""){}

    void display_info() override
    {
        if (get_value() == 1)
        {
            cout << "Mode: Cooling" << endl;
        }
        else{
            cout << "Mode: Heating" << endl;
        }
    }
    void updateValue(int v) override
    {
        set_value(v); 
    }
};

void diagnostics(TemperatureControl t,FanControl f,ModeControl m,string fname);

int main(int argc,char * argv[])
{
    cout << "--- Car Climate Control HMI Simulation ---" <<  endl << endl;
    float temp;
    int speed,mode;
    TemperatureControl t;
    ele_count++;
    FanControl f;
    ele_count++;
    auto fan = make_unique<FanControl>();   
    ModeControl m;
    ele_count++;
    try
    {
        if (argc < 2)
        {
            throw runtime_error("No log file is sending");
        }
        cout << "Enter Cabin Temperature (C): ";
        cin >> temp;
        t.updateValue(temp);

        cout << "Enter Fan Speed(1-10): ";
        cin >> speed;
        f.updateValue(speed);
        
        cout << "Select Mode (1=cooling,2=Heating): ";
        cin >> mode;
        m.updateValue(mode);

        cout << endl << endl;
        t.display_info();
        f.display_info();
        m.display_info();
        cout << endl;
        diagnostics(t,f,m,argv[1]);
        cout << endl;
        if (speed > MAX_FAN_SPEED)
        {
            throw runtime_error("Invalid Fan speed");
        }
    }
    catch(const std::exception& e)
    {
        cerr << "Exception Caught: " << e.what() << endl;
    }
    cout << "total elements: " <<  ele_count << endl;
}


void diagnostics(TemperatureControl t,FanControl f,ModeControl m,string fname)
{
    cout << "--- System diagnostics ---" << endl;
    fstream file(fname,ios::out | ios::app);
    try
    {
        if (!(file))
        {
            throw runtime_error("file not exist");
        }
        if ((t.get_value() > MAX_TEMP) || (t.get_value() < MIN_TEMP))
        {
            cout << "Cabin temperature outside comfort range!" << endl;
            file << "Log: Temperature: " << t.get_value() << " Cabin temperature outside comfort range!\n";
        }
        if (f.get_value() > MAX_FAN_SPEED)
        {
            cout << "Fan speed is too high" << endl;
            file << "Log: Fan speed: " << f.get_value() << " Fan speed is too high\n" << endl;
        }
        cout << "Saving data to Climate_log.txt" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    file.close();
}
