#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;

// ==============================
// Custom Exception
// ==============================
class SensorException : public runtime_error {
public:
    explicit SensorException(const string& msg) : runtime_error(msg) {}
};

// ==============================
// Template Sensor Class
// ==============================
template <typename T>
class Sensor {
    string name;
    T value;
public:
    Sensor(const string& n, T v) : name(n), value(v) {}

    void setValue(T v) {
        if constexpr (is_arithmetic_v<T>) {
            if (v < 0) throw SensorException("Invalid Sensor Value: " + name);
        }
        value = v;
    }

    T getValue() const { return value; }
    string getName() const { return name; }
};

// Forward Declaration
class CalibrationTool;

// ==============================
// Base Class: VehicleECU
// ==============================
class VehicleECU {
private:
    int ecuID;
    string vehicleModel;
protected:
    static int ecuCount;
    const string manufacturer = "Bosch";
public:
    VehicleECU(int id, string model) : ecuID(id), vehicleModel(std::move(model)) {
        ecuCount++;
    }
    virtual ~VehicleECU() { ecuCount--; }

    virtual void diagnose() const = 0;

    friend void displayECUData(const VehicleECU& ecu);
};

int VehicleECU::ecuCount = 0;

// ==============================
// Derived Class: EngineECU
// ==============================
class EngineECU : public VehicleECU {
private:
    float liveRPM;
    volatile float temperature;
    vector<shared_ptr<Sensor<float>>> sensors;

public:
    EngineECU(int id, const string& model, float rpm, float temp)
        : VehicleECU(id, model), liveRPM(rpm), temperature(temp) {}

    void addSensor(const string& name, float value) {
        try {
            auto sensor = make_shared<Sensor<float>>(name, value);
            sensors.push_back(sensor);
            cout << "Sensor added successfully.\n";
        } catch (const SensorException& e) {
            cerr << "[Sensor Error] " << e.what() << endl;
        }
    }

    void showSensors() const {
        cout << "\n--- Sensor List ---" << endl;
        if (sensors.empty()) {
            cout << "No sensors added yet.\n";
            return;
        }
        for (const auto& s : sensors) {
            cout << "Sensor: " << s->getName() << " | Value: " << s->getValue() << endl;
        }
    }

    void diagnose() const override {
        cout << "\n--- Engine ECU Diagnostic Report ---" << endl;
        cout << "Manufacturer: Bosch\n";
        cout << "Total ECUs active: " << ecuCount << endl;

        if (sensors.empty()) {
            cout << "No sensors to diagnose.\n";
            return;
        }

        for (const auto& s : sensors) {
            cout << "Sensor: " << s->getName() << " | Value: " << s->getValue() << endl;
        }
    }

    void writeFaultLog(const string& filename) {
        ofstream file(filename, ios::app);
        if (!file) throw runtime_error("Failed to open log file!");

        bool faultFound = false;
        for (const auto& s : sensors) {
            if (s->getValue() > 100.0f) {
                file << "FAULT: " << s->getName() << " exceeded threshold!\n";
                faultFound = true;
            }
        }
        file.close();

        if (faultFound)
            cout << "Faults logged to " << filename << endl;
        else
            cout << "No faults detected.\n";
    }

    void readFaultLog(const string& filename) const {
        ifstream infile(filename);
        if (!infile) throw runtime_error("Failed to open DTC log file!");

        cout << "\n--- DTC Log Content ---\n";
        string line;
        bool empty = true;
        while (getline(infile, line)) {
            cout << line << endl;
            empty = false;
        }
        if (empty) cout << "No fault data found.\n";
        infile.close();
    }

    void filterSensors(float threshold) {
        cout << "\n--- Sensors Above Threshold (" << threshold << ") ---" << endl;
        auto lambdaFilter = [threshold](const shared_ptr<Sensor<float>>& s) {
            return s->getValue() > threshold;
        };
        for (const auto& s : sensors) {
            if (lambdaFilter(s))
                cout << s->getName() << ": " << s->getValue() << endl;
        }
    }

    friend class CalibrationTool;
    friend void displayECUData(const VehicleECU& ecu);
};

// ==============================
// Friend Class: CalibrationTool
// ==============================
class CalibrationTool {
public:
    void recalibrate(EngineECU& ecu, float newRPM, float newTemp) {
        cout << "\n[Calibration] Recalibrating ECU..." << endl;
        ecu.liveRPM = newRPM;
        ecu.temperature = newTemp;
        cout << "Recalibration complete.\n";
    }
};

// ==============================
// Friend Function
// ==============================
void displayECUData(const VehicleECU& ecu) {
    cout << "\n[Friend Function] ECU internal data displayed (for diagnostics only)\n";
}

// ==============================
// Menu Function
// ==============================
void showMenu() {
    cout << "\n====== Vehicle ECU Simulation Menu ======" << endl;
    cout << "1. Add Sensor" << endl;
    cout << "2. Show All Sensors" << endl;
    cout << "3. Diagnose Engine" << endl;
    cout << "4. Log Faults to File" << endl;
    cout << "5. Read Fault Log" << endl;
    cout << "6. Calibrate Engine" << endl;
    cout << "7. Exit" << endl;
    cout << "Select option: ";
}

// ==============================
// Main Function
// ==============================
int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            throw invalid_argument("Usage: ./VehicleECUSim <log_filename>");
        }

        string logFile = argv[1];
        EngineECU ecu1(101, "Audi-A6", 2500.0f, 90.0f);
        CalibrationTool tool;

        int choice;
        while (true) {
            showMenu();
            cin >> choice;

            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Invalid input. Please enter a number.\n";
                continue;
            }

            switch (choice) {
                case 1: {
                    string name;
                    float value;
                    cout << "Enter sensor name: ";
                    cin >> ws;
                    getline(cin, name);
                    cout << "Enter sensor value: ";
                    cin >> value;
                    ecu1.addSensor(name, value);
                    break;
                }
                case 2:
                    ecu1.showSensors();
                    break;
                case 3:
                    ecu1.diagnose();
                    ecu1.filterSensors(85.0f);
                    break;
                case 4:
                    ecu1.writeFaultLog(logFile);
                    break;
                case 5:
                    ecu1.readFaultLog(logFile);
                    break;
                case 6: {
                    float rpm, temp;
                    cout << "Enter new RPM: ";
                    cin >> rpm;
                    cout << "Enter new Temperature: ";
                    cin >> temp;
                    tool.recalibrate(ecu1, rpm, temp);
                    break;
                }
                case 7:
                    cout << "Exiting program...\n";
                    return 0;
                default:
                    cout << "Invalid option. Try again.\n";
                    break;
            }
        }
    }
    catch (const SensorException& e) {
        cerr << "[Sensor Error] " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "[Exception] " << e.what() << endl;
    }

    cout << "\nProgram exiting normally." << endl;
    return 0;
}
