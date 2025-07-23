#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Mỗi đỉnh là một danh sách liên kết → mảng các con trỏ
Node* adjacency[4];  // giả sử đồ thị có 4 đỉnh: 0, 1, 2, 3

// Hàm thêm cạnh giữa U và V (đồ thị vô hướng)
void addEdge(int U, int V) {
    // Thêm V vào danh sách kề của U
    Node* newNodeV = createNode(V);
    newNodeV->next = adjacency[U];
    adjacency[U] = newNodeV;

    // Thêm U vào danh sách kề của V
    Node* newNodeU = createNode(U);
    newNodeU->next = adjacency[V];
    adjacency[V] = newNodeU;
}

// Hàm in danh sách kề
void printGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("Đỉnh %d: ", i);
        Node* temp = adjacency[i];
        while (temp) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Khởi tạo tất cả danh sách là NULL
    for (int i = 0; i < 4; i++) {
        adjacency[i] = NULL;
    }

    // Thêm các cạnh
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    // In đồ thị
    printGraph(4);

    return 0;
}
