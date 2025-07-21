#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm duyệt cây theo thứ tự trước (Preorder)
void preorderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d\n", root->data);             // 1. In node hiện tại
    preorderTraversal(root->left);          // 2. Duyệt cây con trái
    preorderTraversal(root->right);         // 3. Duyệt cây con phải
}

int main() {
    // Xây cây nhị phân như minh họa
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Duyệt và in theo thứ tự trước
    preorderTraversal(root);

    return 0;
}
