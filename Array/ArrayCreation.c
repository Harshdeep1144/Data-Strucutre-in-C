#include <stdio.h>

int main()
{

    // data_type array_name[size];
    // int numbers[5]; // declaration
    // int numbers[5]; // Declares an integer array of size 5

    // Declaration & initialization
    int numbers1[5] = {10, 20, 30, 40, 50}; // At time of declaration
    int numbers2[5] = {10, 20};             // Partial
    int numbers3[] = {10, 20, 30, 40, 50};  // without size


    printf("First element: %d\n", numbers1[0]);  // Accessing the first element
    printf("Third element: %d\n", numbers1[2]); // Accessing the third element


    return 0;
}