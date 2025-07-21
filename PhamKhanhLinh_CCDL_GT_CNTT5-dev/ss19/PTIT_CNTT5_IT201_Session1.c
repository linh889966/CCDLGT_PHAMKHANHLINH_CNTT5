#include <stdio.h>
#include <stdlib.h>
//b1 định nghĩa cấu trúc
//b2 hàm tạo node mới
//b3 hàm main tạo cây minh hoạ
//b4 in ra

//b1
typedef struct Node {
int data;
struct Node* left;
struct Node* right;
}Node;

//b2
Node* createNode(int giatri){
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data= giatri;
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}

//b3
int main(){
Node* root = createNode(2);
root->left = createNode(3);
root->right = createNode(4);
root->left->left = createNode(5);

printf("Root: %d\n", root->data);
printf("Left child of root: %d\n", root->left->data);
printf("Right child of root: %d\n", root->right->data);
printf("Left child of node 3: %d\n", root->left->left->data);
return 0;
}