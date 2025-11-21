#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
    private:
    string make;
    string model;
    int year;
    float mileage;

    public:

    void addVehicles()
    {
        cout << "--- Add Vehicle ---" << endl;
        cout << "Make: ";
        cin >> make;
        cout << "Model: ";
        cin >> model;
        cout << "Year: ";
        cin >> year;
        cout << "Mileage: ";
        cin >> mileage;
    } 

    void displayVehicles()
    {
        cout << "Make: " << make << "| Model: " << model << "| Year: " << year << "| Mileage: " << mileage << endl;
    }

    string get_model()
    {
        return model;
    }
};

void searchVehicle(vector<Vehicle>& data);

int main()
{
    vector<Vehicle> vehicles_data;

    while(true)
    {
        string choice;
        Vehicle v;
        v.addVehicles();
        vehicles_data.push_back(v);

        cout << "Enter the choice (yes or no): ";
        cin >> choice;
        if (choice == "no" || choice == "NO")
        {
            break;
        }
    }

    for(auto& v: vehicles_data)
    {
        v.displayVehicles();
        printf("\n");
    }

    searchVehicle(vehicles_data);
}

void searchVehicle(vector<Vehicle>& data)
{
    int flag =1;
    string model;
    cout << "Enter the model: ";
    cin >> model;
    for(auto& v: data)
    {
        if (model == v.get_model())
        {
            cout << "Found: "; 
            v.displayVehicles();
            cout << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout  << "Not found on this model " << model << endl;
    }
}