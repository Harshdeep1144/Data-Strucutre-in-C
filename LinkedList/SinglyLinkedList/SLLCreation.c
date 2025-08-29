#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node
{
    int data;
    struct node *next;
};

// Node Creation
struct node *createNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(*newnode));
    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// Create Singly Linked List
struct node *createSLL(struct node *head)
{
    struct node *newnode, *temp;
    int n;
    printf("Enter the Linked list Element : ");
    scanf("%d", &n);

    newnode = createNode(n);

    if (head == NULL)
    {
        temp = head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

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

    for (int i = 0; i < 5; i++)
    {
        head = createSLL(head);
    }

    displayList(head);
    return 0;
}