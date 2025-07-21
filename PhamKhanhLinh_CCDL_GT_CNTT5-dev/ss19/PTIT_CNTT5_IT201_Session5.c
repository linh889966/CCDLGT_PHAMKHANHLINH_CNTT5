#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // để dùng kiểu bool, true, false

// Cấu trúc node
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

// Hàm DFS tìm kiếm giá trị trong cây nhị phân
bool dfsSearch(Node* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    return dfsSearch(root->left, target) || dfsSearch(root->right, target);
}

int main() {
    // Tạo cây như hình minh họa
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    // Tìm kiếm một giá trị
    int x = 5;
    if (dfsSearch(root, x))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
