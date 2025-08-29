#include <stdio.h>
#include <stdlib.h>

void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            printf("%d found at %dth position.\n", key, mid+1);
            return;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d not found.\n", key);
}

int main()
{
    int n = 5;
    int numbers[] = {23, 65, 72, 78, 86};

    binarySearch(numbers, n, 78);
    binarySearch(numbers, n, 32);

    return 0;
}