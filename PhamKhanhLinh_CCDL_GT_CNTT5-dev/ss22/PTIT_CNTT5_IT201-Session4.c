#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int matrix[MAX][MAX];
    int count = 0;

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

    // Đếm số cạnh trong đồ thị vô hướng
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // chỉ duyệt nửa tam giác trên
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("So canh cua do thi: %d\n", count);

    return 0;
}
