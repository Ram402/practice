#include <iostream>
#include <string>
#include <array>
#define Max_Vehicles 20
using namespace std;

class Vehicle
{
    private:
    string model;
    string make;
    int year;
    float mileage;

    public:
    Vehicle(string Make, string Model, int Year, int Mileage): make(Make),model(Model),year(Year),mileage(Mileage)
    {
        cout << " Vehicle Added " << endl;
    }

    ~Vehicle()
    {
        cout << " Vehicle data deleted" << endl;
    }

    string get_make()
    {
        return make;
    }

    string get_model()
    {
        return model;
    }

    int get_year()
    {
        return year;
    }

    float get_mileage()
    {
        return mileage;
    }

    void set_mileage(float Mileage)
    {
        mileage = Mileage;
    }

    virtual void display_Info() = 0;
};

class Car : public Vehicle
{
    string type ;
    public:
    Car(string Make,string Model,int Year,float Mileage,string type) : Vehicle(Make,Model,Year,Mileage),type(type){}

    void display_Info() override
    {
        cout << "Vehicle: " << type <<endl;
        cout << "Make: " << get_make() << endl;
        cout << "Model: " << get_model() << endl;
        cout << "Year: " << get_year() << endl;
        cout << "Mileage: " << get_mileage() << endl;
        
    }

};

class Bike : public Vehicle
{
    string type;
    public:
    Bike(string Make,string Model,int Year,float Mileage,string type) : Vehicle(Make,Model,Year,Mileage),type(type){}
    void display_Info() override
    {
        cout << "Vehicle: " << type <<endl;
        cout << "Make: " << get_make() << endl;
        cout << "Model: " << get_model() << endl;
        cout << "Year: " << get_year() << endl;
        cout << "Mileage: " << get_mileage() << endl;
    }
};

void Add_Vehicle(array<Vehicle* , 20> &V, int *size);
void display_vehicles(array<Vehicle*, 20> &V,int size);
void search_vehicle(array<Vehicle*, 20> &V,int size);
void update_mileage(array<Vehicle*, 20> &V,int size);

int main()
{
    int size = 0,choice;
    array<Vehicle *,20> data;
    cout << "Vehicle Maintenance System" << endl;
    while(true)
    {
        cout << "1.Add Vehicle" << endl << "2.Show all Vehicles" << endl << "3.Search Vehicle by Model" << endl << "4.Update Mileage" << endl << "5.Exit" << endl << endl;
        cout << "\nEnter the option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            {
                if (size == Max_Vehicles)
                {
                    cout << "Vehicle DataBase is full" << endl;
                }
                else
                {
                    Add_Vehicle(data , &size);
                }
                cout << endl;
            }
            break;
        case 2:
            {
                display_vehicles(data,size);
                cout << endl;
            }
            break;
        case 3:
                search_vehicle(data,size);
            break;
        case 4:
                update_mileage(data,size);
            break;
        case 5:
            for(int i=0;i<size;i++) delete data[i];
            exit(0);
        default:
            break;
        }
    }

}

void Add_Vehicle(array<Vehicle* , 20> &V, int *size)
{
    string make,model;
    float mileage;
    int choice = 0,year;
    while(choice != 1 && choice != 2)
    {
        cout << "Enter the choice(1 for Car,2 for Bike): ";
        cin >> choice;
    }
    cout << "Enter the model: ";
    cin >> model;
    cout << "Enter the make: ";
    cin >> make;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the mileage: ";
    cin >> mileage;
    if (choice == 1)
    {
        V[(*size)++] = new Car(make,model,year,mileage,(string)"Car");
    } 
    else
    {
        V[(*size)++] = new Bike(make,model,year,mileage,(string)"Bike");
    }
}

void display_vehicles(array<Vehicle*, 20> &V,int size)
{
    cout << endl << "Vehicle details" << endl;
    for(int i=0;i<size;i++)
    {
        V[i]->display_Info();
        cout << endl;
    }
}

void search_vehicle(array<Vehicle*, 20> &V,int size)
{
    string model;
    int flag = 0;
    cout << "Enter the model: ";
    cin >> model;
    for(int i=0;i<size;i++)
    {
        if (V[i]->get_model() == model)
        {
            cout << "Vehicle found" << endl;
            V[i]->display_Info();
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "No Vehicle found on this model " << model << endl;
}

void update_mileage(array<Vehicle*, 20> &V,int size)
{
    string model;
    float mileage;
    int flag = 0;
    cout << "Enter the model: ";
    cin >> model;
    for(int i=0;i<size;i++)
    {
        if (V[i]->get_model() == model)
        {
            cout << "Vehicle found" << endl;
            // V[i]->display_Info();
            cout << "Enter the updated mileage: ";
            cin >> mileage;
            cout << "Mileage Updated" << endl;
            V[i]->set_mileage(mileage);
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "No Vehicle found on this model " << model << endl;
}