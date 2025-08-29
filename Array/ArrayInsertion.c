#include <stdio.h>

// Insertion at Begining
void insertAtBeg(int arr[], int *size, int item)
{
    for (int i = *size; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = item;
    *size = *size + 1;
}

// Insertion at kth position
void insertAtPos(int arr[], int *size, int item, int pos)
{
    for (int i = *size; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = item;
    *size = *size + 1;
}

// Insertion at end  (by default)
void insertAtEnd(int arr[], int *size, int item)
{
    arr[*size] = item;
    *size = *size + 1;
}

int main()
{

    int numbers[10] = {13, 32, 34, 90, 33};
    int size = 5;

    insertAtBeg(numbers, &size, 12);    // Insert at Begining
    printf("Array after insertion at Begining : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    insertAtPos(numbers, &size, 33, 2); // Insert at position
    printf("Array after insertion at 3rd position : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    insertAtEnd(numbers, &size, 50);  // Insert at end
    printf("Array after insertion at end: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}