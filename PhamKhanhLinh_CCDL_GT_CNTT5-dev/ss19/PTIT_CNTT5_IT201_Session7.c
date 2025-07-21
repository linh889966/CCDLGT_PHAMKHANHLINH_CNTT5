#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Cấu trúc hàng đợi đơn giản để duyệt cây theo level
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

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = node;
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
    Node* result = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return result;
}

// Hàm thêm phần tử mới theo thứ tự level (BFS)
void insertLevelOrder(Node* root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(&q, current->right);
        }
    }
}

// Duyệt tiền thứ để kiểm tra kết quả
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Hàm chính
int main() {
    // Cây ban đầu
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Thêm node mới
    insertLevelOrder(root, 6);

    // In để kiểm tra kết quả
    printf("Preorder sau khi thêm 6:\n");
    preorderTraversal(root);  // Kết quả: 2 3 5 6 4

    return 0;
}
