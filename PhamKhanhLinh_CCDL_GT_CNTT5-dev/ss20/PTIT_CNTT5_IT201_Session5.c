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

// Hàm đệ quy đếm số lá
int countLeaves(Node* root) {
    if (root == NULL) return 0;

    // Nếu node hiện tại là lá
    if (root->left == NULL && root->right == NULL) return 1;

    // Đệ quy đếm lá bên trái + phải
    return countLeaves(root->left) + countLeaves(root->right);
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

    int leafCount = countLeaves(root);
    printf("number of leaves: %d\n", leafCount);

    return 0;
}
