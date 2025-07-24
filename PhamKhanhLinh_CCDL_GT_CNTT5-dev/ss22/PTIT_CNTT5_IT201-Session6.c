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
int v, e; // số đỉnh và số cạnh

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh vào danh sách kề (đồ thị vô hướng)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Hàm DFS
void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            DFS(neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    // Nhập số đỉnh và số cạnh
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    // Khởi tạo danh sách kề
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

    // Nhập đỉnh bắt đầu DFS
    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
