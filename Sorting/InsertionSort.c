#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(numbers, n);
    printArray(numbers, n);

    return 0;
}