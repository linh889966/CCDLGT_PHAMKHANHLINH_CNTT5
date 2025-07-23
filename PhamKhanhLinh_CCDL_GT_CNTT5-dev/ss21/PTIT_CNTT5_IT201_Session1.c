#include <stdio.h>

#define SIZE 3

// Hàm thêm cạnh giữa 2 đỉnh trong đồ thị vô hướng
void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
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
    // Khởi tạo ma trận kề 3x3, ban đầu không có cạnh nào
    int graph[SIZE][SIZE] = {0};

    // Thêm cạnh giữa node 1 và node 2 (chỉ số mảng bắt đầu từ 0)
    addEdge(graph, 1, 2);

    // In kết quả
    printf("Ma tran ke sau khi them canh:\n");
    printGraph(graph);

    return 0;
}
