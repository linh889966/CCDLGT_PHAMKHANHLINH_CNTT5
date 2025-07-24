#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc node cho danh sách kề
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Mảng danh sách kề
Node* adjacency[MAX];
int n; // Số đỉnh

// Tạo một node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh (đồ thị vô hướng)
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacency[u];
    adjacency[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacency[v];
    adjacency[v] = newNode;
}

// In danh sách kề
void printAdjacency() {
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        Node* temp = adjacency[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Khởi tạo mảng danh sách kề về NULL
    for (int i = 0; i < MAX; i++) {
        adjacency[i] = NULL;
    }

    printf("Nhap so dinh: ");
    scanf("%d", &n);

    // Thêm các cạnh
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(0, 4);

    // In danh sách kề
    printf("\nDanh sach ke cua do thi:\n");
    printAdjacency();

    return 0;
}
