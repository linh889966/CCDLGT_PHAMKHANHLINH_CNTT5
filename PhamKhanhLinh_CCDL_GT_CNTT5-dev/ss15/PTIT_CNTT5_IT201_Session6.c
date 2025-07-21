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

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    q->size--;
    return value;
}

void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    Queue* q1 = createQueue(5);
    dequeue(q1);

    Queue* q2 = createQueue(5);
    q2->array[0] = 1;
    q2->array[1] = 2;
    q2->array[2] = 5;
    q2->rear = 2;

    int removed = dequeue(q2);
    printf("return value = %d\n", removed);
    printQueue(q2);

    return 0;
}
