#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Cấu trúc hàng đợi (queue) đơn giản cho BFS
typedef struct QueueNode {
    Node* data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Node* data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    QueueNode* temp = q->front;
    Node* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// BFS tìm kiếm giá trị
bool bfsSearch(Node* root, int target) {
    if (root == NULL) return false;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == target)
            return true;
        if (current->left != NULL)
            enqueue(&q, current->left);
        if (current->right != NULL)
            enqueue(&q, current->right);
    }

    return false;
}

// Hàm chính
int main() {
    // Tạo cây theo ví dụ:
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Tìm kiếm giá trị trong cây
    int x = 3;
    if (bfsSearch(root, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
