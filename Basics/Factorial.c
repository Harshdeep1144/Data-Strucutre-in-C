#include <stdio.h>

// Simple factorial
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}

// Factorial using tail recursion
int fact_tail(int n, int f)
{
    if (n == 0 || n == 1)
    {
        return f;
    }
    else
    {
        return fact_tail(n - 1, n * f);
    }
}

int main()
{
    printf("Factorial without using tail recursion : %d \n", fact(5));
    printf("Factorial using tail recursion : %d \n", fact_tail(5, 1));

    return 0;
}