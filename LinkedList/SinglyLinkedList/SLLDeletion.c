#include <stdio.h>
#include <stdlib.h>

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

// Print List
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

// Delete from Begining
struct node *delFromBeg(struct node *head)
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Can't delete! List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        temp->next = NULL;

        free(temp);
    }

    return head;
}

// Delete form end
struct node *delFromEnd(struct node *head)
{
    struct node *temp1;
    struct node *temp2;

    if (head == NULL)
    {
        printf("Can't delete! List is empty \n");
    }

    // When there is only one element in the list
    if (head->next == NULL)
    {
        head == NULL;
        free(head);

        return NULL;
    }

    temp1 = head;
    temp2 = head->next;

    while (temp2->next != NULL)
    {
        temp1 = temp2; // Important
        temp2 = temp2->next;
    }

    temp1->next = NULL;
    free(temp2);

    return head;
}

// Delete form given position
struct node *delFromPos(struct node *head, int pos)
{
    struct node *temp1;
    struct node *temp2;

    if (head == NULL)
    {
        printf("Can't delete! List is empty \n");
    }

    temp1 = head;
    temp2 = head->next;

    for (int i = 1; i < pos - 1; i++)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = NULL;

    free(temp2);

    return head;
}

int main()
{
    struct node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        head = createSLL(head);
    }

    head = delFromBeg(head);
    displayList(head);

    head = delFromEnd(head);
    displayList(head);

    head = delFromPos(head, 2);
    displayList(head);

    return 0;
}