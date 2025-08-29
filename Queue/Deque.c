#include <stdio.h>
#include <stdlib.h>
#define max 10

int deque[max];
int front = -1;
int rear = -1;

// Insert at the front
void enque_front(int value) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1 && rear == -1) { 
        // First element
        front = rear = 0;
    } else if (front == 0) {
        // Wrap around if front reaches the beginning
        front = max - 1;
    } else {
        front = front - 1;
    }
    deque[front] = value;
    printf("%d inserted at the front of the deque\n", value);
}

// Insert at the rear
void enque_rear(int value) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1 && rear == -1) { 
        // First element
        front = rear = 0;
    } else if (rear == max - 1) {
        // Wrap around if the rear reaches the end
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = value;
    printf("%d inserted at the rear of the deque\n", value);
}

// Remove from the front
void deque_front() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
        return;
    }
    
    int value = deque[front];

    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else if (front == max - 1) {
        // Wrap around if the front reaches the end
        front = 0;
    } else {
        front = front + 1;
    }

    printf("%d deleted from the front of the deque\n", value);
}

// Remove from the rear
void deque_rear() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
        return;
    }
    
    int value = deque[rear];

    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else if (rear == 0) {
        // Wrap around if the rear reaches the beginning
        rear = max - 1;
    } else {
        rear = rear - 1;
    }

    printf("%d deleted from the rear of the deque\n", value);
}

// Main function to test the deque operations
int main() {
    enque_rear(10);
    enque_rear(20);
    enque_front(5);
    enque_front(3);

    printf("\n");
    deque_front();
    deque_rear();

    printf("\n");
    enque_rear(25);
    deque_front();

    printf("\n");
    enque_front(15);
    enque_rear(30);
    deque_rear();

    return 0;
}
