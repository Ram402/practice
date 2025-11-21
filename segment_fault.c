#include <stdio.h>
#include <stdlib.h>

void fill_array(int *arr, int size)
{
    for (int i = 0; i <= size; i++)   // ❌ BUG: <= instead of <
    {
        arr[i] = i * 10;
    }
}

int process(int *p)
{
    return *p + 5;   // If p is NULL → segfault, but not obvious
}

int main()
{
    int size = 5;
    int *arr = malloc(size * sizeof(int));

    fill_array(arr, size);   // Hidden bug inside fill_array()

    int *ptr = NULL;
    int x = rand() % 2;

    if (x == 1)
        ptr = &arr[2];   // Sometimes OK
    else
        ptr = NULL;      // Sometimes ptr remains NULL → segfault later

    printf("Result: %d\n", process(ptr));  // Segfault may happen here

    free(arr);
    return 0;
}
