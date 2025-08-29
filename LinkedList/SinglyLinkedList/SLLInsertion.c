#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Create node
struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// Insert at Begining
struct node *insertAtBeg(struct node *head, int value)
{
    struct node *newnode = createNode(value); // Using create function
    newnode->next = head;
    head = newnode;

    return head;
}

// Insert at end
struct node *insertAtEnd(struct node *head, int value)
{
    struct node *newnode = createNode(value);

    if (head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

// Insert at given position
struct node *insertAtPos(struct node *head, int value, int pos)
{
    struct node *newnode = createNode(value);
    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

// Print the list
void displayList(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("The linked list is empty");
        return;
    }
    
    printf("The Linked List Elements are : ");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insertAtEnd(head, 23);
    head = insertAtEnd(head, 45);

    head = insertAtBeg(head, 12);

    head = insertAtPos(head, 32, 3);

    displayList(head);
    return 0;
}