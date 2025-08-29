#include <stdio.h>

// Deletion at Begining
void deleteAtBeg(int arr[], int *size)
{
    for (int i = 0; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    *size = *size - 1;
}

// Deletion at kth position
void deleteAtPos(int arr[], int *size, int pos)
{

    if (pos > *size || pos < 0)
    {
        printf("Invalid Position \n");
        return;
    }

    for (int i = pos; i < *size; i++)
    {
        arr[i] = arr[i + 1];
    }
    *size = *size - 1;
}

// Deletion at end
void deleteAtEnd(int arr[], int *size)
{
    if (*size > 0)
    {
        *size = *size - 1;
    }
}

int main()
{

    int numbers[] = {23,32,45,90,12};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    deleteAtBeg(numbers, &size);
    printf("Array after deletion at Begining : ");
    for (int i = 0; i < size; i++)
    {
       printf("%d\t", numbers[i]);
    }
    printf("\n");

    deleteAtPos(numbers, &size, 2);
    printf("Array after deletion at 2nd Position : ");
    for (int i = 0; i < size; i++)
    {
       printf("%d\t", numbers[i]);
    }
    printf("\n");

    deleteAtEnd(numbers, &size);
    printf("Array after deletion at end : ");
    for (int i = 0; i < size; i++)
    {
       printf("%d\t", numbers[i]);
    }
    printf("\n");

    return 0;
}