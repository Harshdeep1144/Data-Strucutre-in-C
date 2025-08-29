#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX], top = -1;

// Push Operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full !\n");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
    }
}

// Pop Operation
void pop()
{
    if (top == -1)
    {
        printf("Stack is Empty !\n");
    }
    else
    {
        int value = stack[top];
        top = top - 1;
        printf("%d deleted from the stack successfully. \n", value);
    }
}

// To display the stack elements
void display()
{
    if (top == -1)
    {
        printf("No element to display ! Stack is empty \n");
    }
    else
    {
        printf("The stack elements are : ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main()
{

    push(53);
    push(52);
    push(51);
    display();

    pop();
    display();
    
    return 0;
}