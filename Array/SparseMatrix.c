#include <stdio.h>

int main()
{
    int arr[3][3], count = 0;

    // Input the elements of the matrix
    printf("Enter the elements of the matrix (3x3):\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Count non-zero elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    // Check if the matrix is sparse
    if (count > (3 * 3) / 2)  // More than half of the elements are non-zero
    {
        printf("The matrix is not a sparse matrix.\n");
    }
    else
    {
        // Create a sparse matrix representation (in CSR format)
        int sparse[count][3]; // Each non-zero element has [row, column, value]
        int k = 0;

        // Fill the sparse matrix
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != 0)
                {
                    sparse[k][0] = i;           // Row index
                    sparse[k][1] = j;           // Column index
                    sparse[k][2] = arr[i][j];   // Value
                    k++;
                }
            }
        }

        // Print the sparse matrix in row, column, value format
        printf("\nSparse Matrix Representation (row, column, value):\n");
        printf("Row  Column  Value\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d     %d     %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
        }
    }

    return 0;
}
