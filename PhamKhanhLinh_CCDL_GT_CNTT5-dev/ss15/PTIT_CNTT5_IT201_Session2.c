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

int isFull(Queue* q) {
    return q->rear == q->capacity - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
    q->size++;
    printf("Enqueued %d\n", value);
}

void printQueue(Queue* q) {
    printf("Queue = [ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("]\n");
}

int main() {
    Queue* q = createQueue(5);
    for (int i = 0; i < 5; i++) {
        int value;
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        enqueue(q, value);
        printQueue(q);
    }
    enqueue(q, 999);
    return 0;
}
