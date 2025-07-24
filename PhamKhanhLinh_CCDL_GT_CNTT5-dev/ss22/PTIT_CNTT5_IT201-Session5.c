#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int u, v;
    int k;
    int degree[MAX] = {0}; // mảng lưu bậc của từng đỉnh

    // Nhập số đỉnh và số cạnh
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);

    // Nhập các cạnh
    printf("Nhap cac canh:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        // Vì là đồ thị vô hướng, tăng bậc cho cả hai đỉnh
        degree[u]++;
        degree[v]++;
    }

    // Nhập đỉnh cần kiểm tra
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    printf("So dinh ke voi %d la: %d\n", k, degree[k]);

    return 0;
}
