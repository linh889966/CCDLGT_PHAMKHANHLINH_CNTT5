#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Hàm đệ quy tìm giá trị lớn nhất
int findMax(Node* root) {
    if (root == NULL) return -1; // Hoặc INT_MIN nếu muốn chính xác hơn

    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);

    int maxChild = (maxLeft > maxRight) ? maxLeft : maxRight;
    return (root->data > maxChild) ? root->data : maxChild;
}

int main() {
    // Tạo cây:
    //       2
    //     /   \
    //    3     4
    //   /
    //  5
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int maxVal = findMax(root);
    printf("max value: %d\n", maxVal);

    return 0;
}
