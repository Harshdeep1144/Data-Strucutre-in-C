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
}

// Delete node from Begning
struct node *delFromBeg(struct node *head)
{
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("Can't delete! List is empty");
        return head;
    }

    temp = last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    temp->next = NULL;

    free(temp);

    return head;
}

// Delete node form End
struct node *delFromEnd(struct node *head)
{
    struct node *temp1, *temp2;
    if (head == NULL)
    {
        printf("Can't delete! List is empty");
        return head;
    }

    temp1 = temp2 = head;

    while (temp2->next != head)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }

    temp1->next = head;
    temp2->next = NULL;
    free(temp2);

    return head;
}

// Delete node from nth Position
struct node *delFromPos(struct node *head, int pos)
{
    struct node *temp1 , *temp2;
    if (head == NULL)
    {
        printf("Can't delete! List is empty");
        return head;
    }
    temp1 = temp2 = head;
    for (int i = 1; i < pos; i++)
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
        head = createCLL(head);
    }

    head = delFromBeg(head);
    head = delFromEnd(head);
    head = delFromPos(head,2);

    display(head);

    return 0;
}