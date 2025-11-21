#include <iostream>
#include <fstream>
using namespace std;

constexpr int LOW_FUEL = 10;
constexpr int MAX_TEMP = 120;
class VehicleParameter {
    string name;
    float value;
    string unit;
public:
    VehicleParameter(string n, string u) {
        name = n;
        unit = u;
        value = 0;
    }

    void setValue(float v) {
        if (v < 0)
            throw "Invalid Negative Value!";  
        value = v;
    }

    float get_value()       //bug here not write this function to give the value to the derived classes
    {
        return value;
    }

    virtual void display() {
        cout << name << " : " << value << unit << endl;
    }
};

class Speed : public VehicleParameter {
public:
    Speed():VehicleParameter("Speed", "km/h"){}
    void display() override{
        cout << "Speed Display:" << get_value() << " km/h" << endl;     
    }
};

class Fuel : public VehicleParameter {   //bug here
public:
    Fuel():VehicleParameter("Fuel", "L"){}
    void display() override{
        cout << "Fuel Level: " << get_value() << " L" <<endl;  
        if(get_value() < LOW_FUEL)                  
            cout << "Low Fuel Warning!" << endl;
    }
};

class Temperature : public VehicleParameter {
public:
    Temperature():VehicleParameter("EngineTemp", "C"){}
    void display() override{
        if(get_value() > MAX_TEMP)    //bug here
            cout << "Overheat Warning!" << endl;
        cout << "Temperature: " << get_value() << "C" << endl; //bug here
    }
};

class Diagnostics {
public:
    void showTemp(Temperature t) {    
        if (t.get_value() > 100)    //bug here
            cout << "Diagnostics: Temperature high!" << endl;
    }
};

int main(int argc, char* argv[]) {
    Speed s;
    Fuel f;
    Temperature t;
    try
    {
       if (argc < 2)
        {
            throw runtime_error("file is not given");
        }
        ofstream logFile(argv[1],ios::app);  

        float speed, fuel, temp;
        cout << "Enter speed, fuel, and temperature: ";
        cin >> speed >> fuel >> temp;

        s.setValue(speed);
        f.setValue(fuel);
        t.setValue(temp);

        s.display();
        f.display();
        t.display();

        logFile << "Speed:" << speed << endl;
        logFile << "Fuel:" << fuel << endl;
        logFile << "Temp:" << temp << endl;
        logFile.close();

        Diagnostics d;
        d.showTemp(t);

        cout << "Data Logged Successfully." << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
