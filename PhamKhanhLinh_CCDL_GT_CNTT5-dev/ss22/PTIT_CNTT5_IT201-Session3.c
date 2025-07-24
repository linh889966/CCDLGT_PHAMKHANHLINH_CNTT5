#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Cấu trúc Node cho danh sách liên kết
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Tạo node mới
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm in danh sách kề
void printAdjacencyList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    Node* adjacencyList[MAX] = {NULL}; // Khởi tạo NULL

    // Nhập số đỉnh
    printf("Nhap so dinh: ");
    scanf("%d", &n);

    // Nhập ma trận kề
    printf("Nhap ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Chuyển ma trận sang danh sách kề
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) { // Duyệt ngược để đảm bảo thứ tự từ trái sang phải
            if (matrix[i][j] == 1) {
                Node* newNode = createNode(j);
                newNode->next = adjacencyList[i];
                adjacencyList[i] = newNode;
            }
        }
    }

    // In danh sách kề
    printf("\nDanh sach ke:\n");
    printAdjacencyList(adjacencyList, n);

    return 0;
}
