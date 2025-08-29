#include <stdio.h>

int main()
{
    // One-dimensional
    int oned[5] = {19, 30, 48, 28, 32};
    printf("One-dimensional Array : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", oned[i]);
    }
    printf("\n");

    // Two-dimensional
    int twod[2][3] = {
        {13, 25, 56}, {14, 26, 27}
    };
    printf("Two-dimensional Array : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", twod[i][j]);
        }
        printf("\n");

    }
    printf("\n");


    // Three-dimensional
    int threed[2][3][2] = {
        {{12,11}, {10,34}, {23,34}},
        {{23,34}, {78,23}, {43,21}}
    };
    printf("Three-dimensional Array : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                printf("%d ",threed[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    


    return 0;
}