#include <stdio.h>

void max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    // If left child exists and is greater than root
    if (l <= n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // If right child exists and is greater than root
    if (r <= n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        max_heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build a max_heap
    for (int i = n / 2; i >= 1; i--)
    {
        max_heapify(arr, n, i);
    }

    // Deleting and sorting array elements
    for (int i = n; i > 1; i--)
    {
        // Move current root to end
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        max_heapify(arr, i - 1, 1);
    }
}

// To print arrary elements
void printArray(int arr[], int n)
{

    printf("The array elements are: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 5;
    int numbers[] = {0, 56, 41, 78, 32, 12}; // Extra 0 at index 0 (unused)

    printArray(numbers, n);
    heapSort(numbers, n);
    printArray(numbers, n);

    return 0;
}