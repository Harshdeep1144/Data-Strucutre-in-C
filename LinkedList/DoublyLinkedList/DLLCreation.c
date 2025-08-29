#include <stdio.h>
#include <stdlib.h>

// Structure definition for doubly linked list
struct node
{
    int data;
    struct node *next, *prev;
};

// Node creation for doubly linked list
struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

// Doubly linked list creation
struct node *createDLL(struct node *head)
{
    struct node *newnode, *temp;
    int n;
    printf("Enter the linked list element : ");
    scanf("%d", &n);

    newnode = createNode(n);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

// Print the doubly linked list
void displayList(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("The list is empty \n");
        return;
    }
    printf("The Doubly linked list elements are : ");

    temp = head;
    while (temp->next != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main()
{
    struct node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        head = createDLL(head);
    }

    displayList(head);

    return 0;
}