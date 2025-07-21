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

// Duyệt hậu thứ (Postorder Traversal): Left → Right → Root
void postorderTraversal(Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}

int main() {
    // Xây cây như hình minh hoạ
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Duyệt hậu thứ và in ra kết quả
    postorderTraversal(root);

    return 0;
}
