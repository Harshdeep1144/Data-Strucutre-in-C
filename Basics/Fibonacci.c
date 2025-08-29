#include <stdio.h>
#include <stdio.h>

// Simple Fibonacci
int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

// Fibonacci using tail recursion
int fibo_tail(int n, int a, int b) // a = 0 and b = 1
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        return fibo_tail(n-1, b, a + b);
    }
}

int main()
{
    printf("Fibonacci without using tail recursion : %d \n", fibo(5));
    printf("Fibonacci using tail recursion : %d \n", fibo_tail(5, 0, 1));

    return 0;
}