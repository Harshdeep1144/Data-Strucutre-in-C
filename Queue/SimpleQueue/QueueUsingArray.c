#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

// To insert element in simple queue
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("The Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
        printf("%d inserted in the queue\n", value);
    }
    else
    {
        rear = rear + 1;
        queue[rear] = value;
        printf("%d inserted in the queue\n", value);
    }
}

// To delete element from the simple queue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty \n");
    }
    else if (front == rear)
    {
        int value = queue[front];
        printf("%d deleted from the queue\n", value);
        front = rear = -1;
    }
    else
    {
        int value = queue[front];
        front = front + 1;
        printf("%d deleted from the queue\n", value);
    }
}

// Print the elements of queue
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty \n");
        return;
    }

    printf("The queue elements are : ");
    for (int i = front; i <= rear ; i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{

    enqueue(23);
    enqueue(12);
    enqueue(36);
    enqueue(25);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}