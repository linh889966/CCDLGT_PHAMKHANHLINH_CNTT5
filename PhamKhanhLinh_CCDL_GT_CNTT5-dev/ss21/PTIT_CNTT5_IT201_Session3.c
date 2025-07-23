#include <stdio.h>

#define SIZE 3  // Số lượng đỉnh

// Hàm thêm cạnh có hướng từ startNode đến endNode
void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

// Hàm in ma trận kề
void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Khởi tạo ma trận 3x3 với giá trị 0 (chưa có cạnh nào)
    int graph[SIZE][SIZE] = {0};

    // Thêm cạnh có hướng từ đỉnh 1 đến đỉnh 2
    addEdge(graph, 1, 2);

    // In kết quả
    printf("Ma tran ke (do thi co huong):\n");
    printGraph(graph);

    return 0;
}
