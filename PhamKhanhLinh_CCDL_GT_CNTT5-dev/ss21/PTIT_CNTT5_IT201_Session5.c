#include <stdio.h>
#include <stdlib.h>

#define SIZE 3  // Số đỉnh của đồ thị

// Cấu trúc 1 node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm cạnh vào đồ thị vô hướng
void addEdge(Node* graph[], int startNode, int endNode) {
    // Thêm endNode vào danh sách của startNode
    Node* newNode1 = createNode(endNode);
    newNode1->next = graph[startNode];
    graph[startNode] = newNode1;

    // Thêm startNode vào danh sách của endNode (vì đồ thị vô hướng)
    Node* newNode2 = createNode(startNode);
    newNode2->next = graph[endNode];
    graph[endNode] = newNode2;
}

// Hàm hiển thị danh sách kề
void printGraph(Node* graph[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        Node* temp = graph[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Mảng chứa danh sách kề, ban đầu NULL
    Node* graph[SIZE] = {NULL};

    // Ví dụ theo bài: thêm các cạnh
    addEdge(graph, 1, 2);
    addEdge(graph, 0, 1);

    // In danh sách kề
    printf("Danh sach ke cua do thi vo huong:\n");
    printGraph(graph);

    return 0;
}
