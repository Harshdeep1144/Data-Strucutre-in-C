#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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
    struct node *temp = head;
    struct node *newnode = createNode(value);

    if (head == NULL)
    {
        head = newnode; 
        newnode->next = head;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        newnode->next = head;
        head = newnode;
        temp->next = newnode;
    }

    return head;
}

// Insert at end
struct node *insertAtEnd(struct node *head, int value)
{
    struct node *newnode, *temp;
    newnode = createNode(value);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return head;
}

// Insert at position
struct node *insertAtPos(struct node *head, int value, int pos)
{
    struct node *newnode, *temp;
    newnode = createNode(value);

    temp = head;

    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == head)
        {
            printf("Position out of range\n");
            return head;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;

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
}

int main()
{
    struct node *head = NULL;

    head = insertAtEnd(head, 11);
    head = insertAtEnd(head, 13);

    head = insertAtBeg(head, 9);
    
    head = insertAtPos(head, 10, 4);

    display(head);

    return 0;
}