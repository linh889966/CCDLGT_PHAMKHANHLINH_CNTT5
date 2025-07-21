#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LENGTH 31

typedef struct {
    char data[MAX][NAME_LENGTH];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(Queue* q) {
    return q->size == MAX;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, char name[]) {
    if (isFull(q)) {
        printf("Hang doi rong\n");
        return;
    }
    q->rear++;
    strcpy(q->data[q->rear], name);
    q->size++;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phuc vu khach hang: %s\n", q->data[q->front]);
    q->front++;
    q->size--;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Danh sach khach dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->data[i]);
    }
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char name[NAME_LENGTH];

    while (1) {
        printf("\n1. Them khach hang\n");
        printf("2. Phuc vu khach\n");
        printf("3. Danh sach khach\n");
        printf("4. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            if (isFull(&q)) {
                printf("Hang doi day\n");
            } else {
                printf("Nhap ten khach hang: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;
                enqueue(&q, name);
            }
        } else if (choice == 2) {
            dequeue(&q);
        } else if (choice == 3) {
            printQueue(&q);
        } else if (choice == 4) {
            break;
        } else {
            printf("Lua chon khong hop le\n");
        }
    }

    return 0;
}
