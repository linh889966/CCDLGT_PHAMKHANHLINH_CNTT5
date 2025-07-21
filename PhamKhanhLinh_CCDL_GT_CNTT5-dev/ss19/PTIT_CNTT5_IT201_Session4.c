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

// Duyệt trung thứ (Inorder Traversal): Left → Root → Right
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Xây cây nhị phân như hình
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Duyệt và in kết quả theo thứ tự trung
    inorderTraversal(root);

    return 0;
}
