#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void bstToGstHelper(struct TreeNode* root, int* sum) {
    if (root == NULL) return;

    bstToGstHelper(root->right, sum);

    *sum += root->val;
    root->val = *sum;
    bstToGstHelper(root->left, sum);
}

struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    bstToGstHelper(root, &sum);
    return root;
}

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}

//  test case
int main() {
    //  create sample
    struct TreeNode* root = createTreeNode(4);
    root->left = createTreeNode(1);
    root->right = createTreeNode(6);
    root->left->left = createTreeNode(0);
    root->left->right = createTreeNode(2);
    root->left->right->right = createTreeNode(3);
    root->right->left = createTreeNode(5);
    root->right->right = createTreeNode(7);
    root->right->right->right = createTreeNode(8);
    
    root = bstToGst(root);
    printf("In-order traversal of the Greater Tree: ");
    printInOrder(root);   
    return 0;
}
