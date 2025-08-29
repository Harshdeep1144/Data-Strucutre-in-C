#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = high;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;
}

// Perform quick sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// To print arrary elements
void printArray(int arr[], int n)
{

    printf("The array elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 5;
    int numbers[] = {56, 41, 78, 32, 12};

    printArray(numbers, n);
    quickSort(numbers, 0, n-1);
    printArray(numbers, n);

    return 0;
}