#include <stdio.h>
#include <stdlib.h>

// define the node structure
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

// Print Function for LinkedList
void displayList(struct node *head)
{
    struct node *temp = head;

    printf("Linked List Elements are : ");
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
    struct node *A, *B, *C;

    // Creating nodes
    head = createNode(12);
    A = createNode(14);
    B = createNode(15);
    C = createNode(18);

    head->next = A;
    A->next = B;
    B->next = C;
    C->next = NULL;

    displayList(head);

    return 0;
}