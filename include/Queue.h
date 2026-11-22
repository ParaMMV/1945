#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define MAX_SIZE 5 

typedef struct {
    int items[MAX_SIZE]; 
    int front;           
    int rear;           
} Queue;

void initQueue(Queue *q);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);

#endif