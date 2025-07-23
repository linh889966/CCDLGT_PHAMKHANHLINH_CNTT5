#include <stdio.h>

#define SIZE 3

// Hàm thêm cạnh có hướng từ startNode đến endNode
void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

// Hàm in ma trận kề
void printGraph(int graph[SIZE][SIZE]) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Khởi tạo đồ thị chưa có cạnh nào
    int graph[SIZE][SIZE] = {0};

    // Thêm các cạnh theo mô tả
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    // In ma trận kết quả
    printGraph(graph);

    return 0;
}
