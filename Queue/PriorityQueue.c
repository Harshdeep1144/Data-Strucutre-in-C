#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int value;
    int priority;
} Element;

Element priorityQueue[MAX];
int size = 0; // Keeps track of the current number of elements in the queue

// Function to enqueue an element into the priority queue
void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("The Priority Queue is full\n");
        return;
    }

    // Insert the new element at the end
    priorityQueue[size].value = value;
    priorityQueue[size].priority = priority;
    size++;

    // Sort the queue based on priority (higher priority first)
    for (int i = size - 1; i > 0; i--) {
        if (priorityQueue[i].priority > priorityQueue[i - 1].priority) {
            // Swap the elements
            Element temp = priorityQueue[i];
            priorityQueue[i] = priorityQueue[i - 1];
            priorityQueue[i - 1] = temp;
        } else {
            break; // No need to check further
        }
    }

    printf("Element %d with priority %d inserted into the priority queue\n", value, priority);
}

// Function to dequeue the highest-priority element
void dequeue() {
    if (size == 0) {
        printf("The Priority Queue is empty\n");
        return;
    }

    // The first element is always the highest-priority element
    Element dequeued = priorityQueue[0];

    // Shift all elements one position to the left
    for (int i = 0; i < size - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    size--;

    printf("Element %d with priority %d removed from the priority queue\n", dequeued.value, dequeued.priority);
}

// Function to display the elements of the priority queue
void display() {
    if (size == 0) {
        printf("The Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue: \n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", priorityQueue[i].value, priorityQueue[i].priority);
    }
}

int main() {
    enqueue(10, 2); // Value: 10, Priority: 2
    enqueue(20, 1); // Value: 20, Priority: 1
    enqueue(30, 3); // Value: 30, Priority: 3
    enqueue(40, 2); // Value: 40, Priority: 2

    display();
    printf("\n");

    dequeue(); // Removes the element with the highest priority (30)
    display();
    printf("\n");

    enqueue(50, 4); // Value: 50, Priority: 4
    display();
    printf("\n");

    dequeue(); // Removes the element with the highest priority (50)
    display();

    return 0;
}
