#include <stdio.h>
#include <stdlib.h>
#define max 10

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % max == front)
    {
        printf("Circular Queue is full\n");
        return;
    }

    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = value;
    }
    else
    {
        rear = (rear + 1) % max;
        queue[rear] = value;
    }
    printf("%d inserted in the circular Queue\n", value);
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    int value = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % max;
    }
    printf("%d deleted from the Circular Queue \n", value);
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("The Circular Queue elements are : ");
    
    for (int i = front; i != rear; i = (i + 1) % max)
    {
        printf("%d ", queue[i]);
    }

    printf("%d\n", queue[rear]);
}

int main(){

    enqueue(23);
    enqueue(34);
    enqueue(56);
    enqueue(24);
    enqueue(65);

    dequeue();
    dequeue();
    
    display();

    return 0;
}


