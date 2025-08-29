#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory Overflow !\n");
    }
    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode; // Update the rear pointer
    }
    printf("%d inserted in the queue \n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp;

    temp = front;
    int data = temp->data;
    front = front->next;

    if (front == NULL) // If the queue becomes empty
    {
        rear = NULL;
    }

    printf("%d deleted from queue. \n", data);

    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty! \n");
        return;
    }

    struct node *temp;

    temp = front;
    printf("The elements of Queue are : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{

    enqueue(12);
    enqueue(32);
    enqueue(21);
    enqueue(34);
    enqueue(87);

    dequeue();
    dequeue();

    display();

    return 0;
}