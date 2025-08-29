#include <stdio.h>

void merge(int arr[], int mid, int l, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // i -> traverses leftArr
    // j -> traverses rightArr
    // k -> traverses the original array arr
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        mergeSort(arr, l, mid - 1);
        mergeSort(arr, mid + 1, h);
        merge(arr, mid, l, h);
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
    mergeSort(numbers, 0, n - 1);
    printArray(numbers, n);

    return 0;
}