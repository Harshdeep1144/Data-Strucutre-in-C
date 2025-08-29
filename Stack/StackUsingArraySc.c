#include <stdio.h>
#include <stdlib.h>

int MAX, top = -1;

// Push Operation
void push(int stack[], int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full!\n");
    }
    else
    {
        top = top + 1;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Pop Operation
void pop(int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        int value = stack[top];
        top = top - 1;
        printf("%d deleted from the stack successfully.\n", value);
    }
}

// Display Stack Elements
void display(int stack[])
{
    if (top == -1)
    {
        printf("No element to display! Stack is empty.\n");
    }
    else
    {
        printf("The stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    int stack[MAX];

    while (1)
    {
        printf("\n");
        printf("Press 1 to Push\n");
        printf("Press 2 to Pop\n");
        printf("Press 3 to Display\n");
        printf("Press 4 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push/insert into the stack: ");
            scanf("%d", &value);
            push(stack, value);
            break;

        case 2:
            pop(stack);
            break;

        case 3:
            display(stack);
            break;

        case 4:
            printf("Exiting....\n");
            exit(0); // Exit the program

        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
