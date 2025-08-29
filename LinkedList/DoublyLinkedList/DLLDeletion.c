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
    printf("%d\n", temp->data);
}

// Delete node from begining in doubly linked list
struct node *delFromBeg(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Can't delete! List is empty\n");
        return head;
    }

    temp = head;

    head = head->next;
    head->prev = NULL;
    temp->next = NULL;

    free(temp);

    return head;
}

// Delete node from end in doubly linked list
struct node *delFromEnd(struct node *head)
{
    struct node *temp1, *temp2;

    if (head == NULL)
    {
        printf("Can't delete! List is empty\n");
        return head;
    }

    temp2 = head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp1 = temp2->prev;
    temp1->next = NULL;

    free(temp2);

    return head;
}

// Delete node form nth position in doubly linked list
struct node *delFromPos(struct node *head, int pos)
{
    struct node *temp1, *temp2;

    if (head == NULL)
    {
        printf("Can't delete! List is empty\n");
        return head;
    }

    temp2 = head;
    for (int i = 1; i < pos; i++)
    {
        temp2 = temp2->next;
    }

    temp1 = temp2->prev;
    temp1->next = temp2->next;
    temp2->next = NULL;
    temp2->prev = NULL;

    free(temp2);

    return head;
}

int main()
{
    struct node *head = NULL;

    for (int i = 0; i < 10; i++)
    {
        head = createDLL(head);
    }

    displayList(head);

    head = delFromBeg(head);
    displayList(head);

    head = delFromEnd(head);
    displayList(head);

    head = delFromPos(head,4);
    displayList(head);

    return 0;
}