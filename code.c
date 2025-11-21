#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30

// Function to calculate average
float calculateAverage(int *marks, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)  //bug here  
        sum += marks[i];
    return (float)sum / n;
}

// Function to find index of highest score
int findTopper(int *marks, int n) {
    int topIndex = 0;
    for(int i = 1; i < n; i++) {
        if(marks[topIndex] < marks[i])
            topIndex = i; //Bug here        
    }
    return topIndex;
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n); //Bug here               

    char **names = (char **)malloc(n * sizeof(char *));
    if (names == NULL)
    {
        printf("Memory not allocated\n");
        return 1;
    }
    int *marks = malloc(sizeof(int) * n); 
    if (marks == NULL)
    {
        printf("Memory not allocated\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        names[i] = malloc(MAX_NAME_LEN);        //bug here
        if (names[i] == NULL)
        {
            printf("Memory not allocated\n");
            return 1;
        }
        printf("Enter name and marks of student %d: ", i + 1);
        scanf("%s %d", names[i], &marks[i]);
    }

    float avg = calculateAverage(marks, n);
    int topper = findTopper(marks, n);

    printf("\nAverage Marks: %.2f\n", avg);
    printf("Topper: %s with %d marks\n", names[topper], marks[topper]);

    for(int i = 0; i < n; i++)
        free(names[i]);
    free(names);
    free(marks);

    return 0;
}


