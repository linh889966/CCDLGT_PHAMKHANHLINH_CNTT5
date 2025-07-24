#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc Node cho danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;
int v, e;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh (đồ thị vô hướng)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Hàm thêm vào hàng đợi
void enqueue(int value) {
    queue[++rear] = value;
}

// Hàm lấy phần tử khỏi hàng đợi
int dequeue() {
    return queue[front++];
}

// Kiểm tra hàng đợi rỗng
int isEmpty() {
    return front > rear;
}

// BFS
void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }
            temp = temp->next;
        }
    }
}

int main() {
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    // Khởi tạo danh sách kề và mảng visited
    for (int i = 0; i < v; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Nhập danh sách cạnh
    printf("Nhap danh sach %d canh (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Nhập đỉnh bắt đầu BFS
    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start);
    printf("\n");

    return 0;
}
