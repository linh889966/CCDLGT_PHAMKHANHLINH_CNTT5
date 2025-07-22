#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàng đợi để duyệt level-order
typedef struct {
    Node* data[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* node) {
    q->data[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->data[q->front++];
}

// Thêm phần tử mới theo thứ tự duyệt mức
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

// Duyệt theo mức (để kiểm tra)
void printLevelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* curr = dequeue(&q);
        printf("%d ", curr->data);
        if (curr->left) enqueue(&q, curr->left);
        if (curr->right) enqueue(&q, curr->right);
    }
}

int main() {
    // Khởi tạo cây mẫu ban đầu
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Thêm giá trị mới
    int newValue = 6;
    insertLevelOrder(root, newValue);

    // In kết quả sau khi thêm
    printf("Cay sau khi them %d:\n", newValue);
    printLevelOrder(root);

    return 0;
}
