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

int isEmpty(Queue* q) {
    return q->rear < q->front;
}

int main() {
    Queue* q1 = createQueue(5);
    printf("%s\n", isEmpty(q1) ? "true" : "false");

    Queue* q2 = createQueue(5);
    q2->array[0] = 1;
    q2->array[1] = 2;
    q2->array[2] = 5;
    q2->rear = 2;
    printf("%s\n", isEmpty(q2) ? "true" : "false");

    return 0;
}
