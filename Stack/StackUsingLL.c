#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// To insert element in stack
void push(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// To delete element from stack
void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    int value = temp->data;
    top = top->next;
    temp->next = NULL;

    free(temp);

    printf("%d deleted from the stack \n", value);
}

// To display stack elements
void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;
    printf("The elements of stack are : ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    display();

    pop();
    display();

    return 0;
}