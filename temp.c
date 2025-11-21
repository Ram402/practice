#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// optional data (union)
typedef union optional_vehicle_data
{
    int engineCC;
    float batteryCapacity;
} optional_data_t;


// main vehicle structure
typedef struct vehicle
{
    char make[20];
    char model[20];
    int year;
    float mileage;
    optional_data_t data;
} vehicle_t;


// packed temporary structure
#pragma pack(1)
typedef struct vehicle_temp
{
    char make[20];
    char model[20];
    int year;
    float mileage;
    optional_data_t data;
} vehicle_temp;


// function declarations
void addVehicles(vehicle_t *data, int count);
void displayAllVehicles(vehicle_t *data, int count);
void searchVehicles(vehicle_t *data, int count, char *search);



int main()
{
    int count;
    char search[20];

    printf("Enter the number of vehicles: ");
    scanf("%d", &count);

    // allocate memory for vehicle array
    vehicle_t *vehicle_data = (vehicle_t *)malloc(count * sizeof(vehicle_t));
    if (vehicle_data == NULL)
    {
        printf("Memory not allocated for vehicle data\n");
        return 1;
    }

    printf("\n");

    // Add vehicles (LOOP INSIDE FUNCTION)
    addVehicles(vehicle_data, count);

    printf("\n");

    // Display vehicles (LOOP INSIDE FUNCTION)
    displayAllVehicles(vehicle_data, count);

    printf("\n");

    // Search vehicles (LOOP INSIDE FUNCTION)
    printf("Search model: ");
    scanf(" %[^\n]", search);
    searchVehicles(vehicle_data, count, search);

    printf("\n");

    // free allocated memory
    free(vehicle_data);

    // size comparison
    printf("With padding, vehicle structure size is %lu\n", sizeof(vehicle_t));
    printf("Without padding, vehicle_temp structure size is %lu\n", sizeof(vehicle_temp));
    printf("(Explanation: Both sizes match here because structure members are naturally aligned.)\n");

    return 0;
}



// ---------------------------------------------------------
// Add ALL vehicles using loop inside the function
// ---------------------------------------------------------
void addVehicles(vehicle_t *data, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("--- Add Vehicle %d ---\n", i + 1);

        printf("Make: ");
        scanf(" %[^\n]", data[i].make);

        printf("Model: ");
        scanf(" %[^\n]", data[i].model);

        printf("Year: ");
        scanf("%d", &data[i].year);

        printf("Mileage: ");
        scanf("%f", &data[i].mileage);

        printf("\n");
    }
}



// ---------------------------------------------------------
// Display ALL vehicles using loop inside the function
// ---------------------------------------------------------
void displayAllVehicles(vehicle_t *data, int count)
{
    printf("--- All Vehicles ---\n");

    for (int i = 0; i < count; i++)
    {
        printf("Make: %s | Model: %s | Year: %d | Mileage: %.2f\n",
               data[i].make,
               data[i].model,
               data[i].year,
               data[i].mileage);
    }
}



// ---------------------------------------------------------
// Search ALL vehicles using loop inside the function
// ---------------------------------------------------------
void searchVehicles(vehicle_t *data, int count, char *search)
{
    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(data[i].model, search) == 0)
        {
            printf("Found: %s (%s, %d)\n",
                   data[i].make,
                   data[i].model,
                   data[i].year);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Vehicle not found for model: %s\n", search);
    }
}
