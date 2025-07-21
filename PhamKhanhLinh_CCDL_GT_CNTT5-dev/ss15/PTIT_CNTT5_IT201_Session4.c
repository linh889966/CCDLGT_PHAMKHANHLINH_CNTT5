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

void viewQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
}

int main() {
    Queue* q1 = createQueue(5);
    viewQueue(q1);

    Queue* q2 = createQueue(5);
    q2->array[0] = 1;
    q2->array[1] = 2;
    q2->array[2] = 5;
    q2->rear = 2;
    viewQueue(q2);

    return 0;
}
