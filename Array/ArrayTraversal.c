#include <stdio.h>

// Array Traversal
void arrayTraversal(int arr[], int *size)
{
    printf("Array Elements are : ");
    for (int i = 0; i < *size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// Array Reverse Traversal
void arrayRevTraversal(int arr[], int *size)
{
    printf("Array Elements In Reverse Order are : ");
    for (int i = *size-1; i >= 0; i--)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int numbers[] = {11, 32, 31, 42, 18};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    arrayTraversal(numbers, &size);
    arrayRevTraversal(numbers, &size);

    return 0;
}