#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *array;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->array = (int*)malloc(capacity * sizeof(int));
    return q;
}
