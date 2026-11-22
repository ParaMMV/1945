#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->front == -1; // Check whether front is -1 to determine if the queue is empty
}

bool isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full, cannot add %d\n", value);
        return;
    }
    
    // If this is the first item, set front to 0
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->rear++;                   // Move rear forward by one slot
    q->items[q->rear] = value;   // Place the data in the slot pointed to by rear
    printf("Successfully added %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty, cannot remove data\n");
        return -1; // Return -1 to indicate an error or no data
    }
    
    int item = q->items[q->front]; // Take out the frontmost data
    q->front++;                    // Move front forward by one slot
    
    // If the queue becomes empty after removal, reset both front and rear to -1
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    
    return item;
}