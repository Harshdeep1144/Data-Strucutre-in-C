#include <stdio.h>
#include <stdlib.h>

// Same structure as singly linked list (structure definition of node)
struct node
{
    int data;
    struct node *next;
};

// Same as singly linked list (Node creation)
struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// Creation of circular linked list
struct node *createCLL(struct node *head)
{
    struct node *newnode, *temp;

    int n;
    printf("Enter the Circular linked list element : ");
    scanf("%d", &n);

    newnode = createNode(n);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }

    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

    return head;
}

// Print Circlular linked list
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty");
        return;
    }

    struct node *temp = head;
    printf("The linked list elements are : ");

    // Using while loop
    while (temp->next != head)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);

    // Using do while loop
    // do
    // {
    //     printf("%d->", temp->data);
    //     temp = temp->next;
    // } while (temp != head);
}

int main()
{
    struct node *head = NULL;

    for (int i = 0; i < 3; i++)
    {
        head = createCLL(head);
    }

    display(head);
    return 0;
}