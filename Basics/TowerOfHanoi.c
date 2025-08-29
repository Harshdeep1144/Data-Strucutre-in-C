#include <stdio.h>

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("Move %c to %c \n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    char a = 'A', b = 'B', c = 'C';

    printf("Enter the number of disks for Tower of Hanoi: ");
    scanf("%d", &n);

    printf("The Tower of Hanoi steps for %d disks are: \n", n);
    TOH(n, a, b, c);

    return 0;
}