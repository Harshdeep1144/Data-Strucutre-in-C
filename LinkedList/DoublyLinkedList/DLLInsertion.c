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

// Insert at Begining
struct node *insertAtBeg(struct node *head, int value)
{

    struct node *newnode = createNode(value);

    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    return head;
}

// Insert node at end
struct node *insertAtEnd(struct node *head, int value)
{
    struct node *temp;
    struct node *newnode = createNode(value);

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

// Insert at given position
struct node *insertAtPos(struct node *head, int value, int pos)
{
    struct node *temp;
    struct node *newnode = createNode(value);

    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;

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
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insertAtEnd(head, 45);
    head = insertAtEnd(head, 46);

    head = insertAtBeg(head, 12);
    head = insertAtBeg(head, 11);

    head = insertAtPos(head, 13,3);
    displayList(head);

    return 0;
}