#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//optional data
typedef union optional_vehicle_data
{
    int engineCC;
    float batteryCapacity;
}optional_data_t;


//vehicle structure
typedef struct vehicle
{
    char make[20];
    char model[20];
    int year;
    float mileage;
    optional_data_t data;
}vehicle_t;

//temporary structure for the checking the size difference
#pragma pack(1)
typedef struct vehicle_temp
{
    char make[20];
    char model[20];
    int year;
    float mileage;
    optional_data_t data;
}vehicle_temp;



void addVehicle(vehicle_t * data);
void displayVehicles(vehicle_t data);
int  serachVehicle(vehicle_t data,char * search);


int main()
{
    int count;
    char search[20];
    printf("Enter the number of vehicles:");
    scanf("%d",&count);

    //allocating memory for the data
    vehicle_t * vehicle_data =(vehicle_t *)malloc(count * sizeof(vehicle_t));
    if (vehicle_data == NULL)
    {
        printf("Memory not alloacted for the vehicle data");
        return 1;
    }
    printf("\n");

    //adding the vehicles
    for(int i=0;i<count;i++)
    {
        printf("--- Add Vehicle %d ---\n",i+1);
        addVehicle(&vehicle_data[i]);
        printf("\n");
    }
    
    //display the vehicles data
    printf("--- All Vehicles ---\n");
    vehicle_t * temp = vehicle_data;
    for(int i=0;i<count;i++)
    {
        displayVehicles(*(temp++));
    }
    printf("\n");

    //serach the vehicle
    printf("Search model: ");
    scanf(" %[^\n]s",search);
    for(int i=0;i<count;i++)
    {
        int res = serachVehicle(vehicle_data[i],search);
        if ((res == 1) && (i == (count-1)))
        {
            printf("Vehicle not found on this model %s\n",search);
        }
    }

    //deallocating the memory
    free(vehicle_data);

    //checking the size difference of structures with padding and without padding
    printf("\nWith padding the vehicle structure size is %d\n",sizeof(vehicle_t));
    printf("With out padding the vehicle structure size is %d\n",sizeof(vehicle_temp));
    printf("\n(Explanation: The size is same in with padding and without padding because the members are aligned correctly with size. so there is no difference and no extra bytes are used.)\n");
}


void addVehicle(vehicle_t * data)
{
    printf("Make: ");
    scanf(" %[^\n]s",data->make);
    printf("Model: ");
    scanf(" %[^\n]s",data->model);
    printf("Year: ");
    scanf("%d",&data->year);
    printf("Mileage: ");
    scanf("%f",&data->mileage);
}

void displayVehicles(vehicle_t data)
{
    printf("Make: %s | Model: %s | Year: %d | Mileage: %.2f\n",data.make,data.model,data.year,data.mileage);
}

int  serachVehicle(vehicle_t data,char * search)
{
    if ((strcmp(data.model,search)) == 0)
    {
        printf("Found: %s (%s, %d)\n",data.make,data.model,data.year);
        return 0;
    }
    else
        return 1;
}