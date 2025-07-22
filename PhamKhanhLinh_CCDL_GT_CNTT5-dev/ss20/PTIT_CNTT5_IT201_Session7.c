#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node của cây nhị phân
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm hiển thị cây theo dạng tiền tự (pre-order)
void printPreorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Hàm main
int main() {
    // Tạo các node theo sơ đồ:
    //        2
    //      /   \
    //     3     4
    //    /
    //   5

    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // In kết quả duyệt cây (kiểm tra)
    printf("Duyet tien tu (preorder): ");
    printPreorder(root);

    // Giải phóng bộ nhớ (tùy chọn)
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
