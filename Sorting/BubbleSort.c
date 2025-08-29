#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // To check swapping is done or not
            }
        }
        if (swapped == 0)
        {
            break;
        }
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
    bubbleSort(numbers, n);
    printArray(numbers, n);

    return 0;
}