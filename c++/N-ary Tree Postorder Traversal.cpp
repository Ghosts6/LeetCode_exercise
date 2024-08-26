#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

void postorderTraversal(struct Node* root, int* result, int* returnSize) {
    if (root == NULL) return;

    for (int i = 0; i < root->numChildren; i++) {
        postorderTraversal(root->children[i], result, returnSize);
    }

    result[(*returnSize)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    int* result = (int*)malloc(10000 * sizeof(int)); 
    postorderTraversal(root, result, returnSize);

    return result;
}

struct Node* createNode(int val, int numChildren) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->numChildren = numChildren;
    newNode->children = (struct Node**)malloc(numChildren * sizeof(struct Node*));
    return newNode;
}
//  test case
int main() {
    struct Node* root = createNode(1, 3);
    root->children[0] = createNode(3, 2);
    root->children[1] = createNode(2, 0);
    root->children[2] = createNode(4, 0);
    root->children[0]->children[0] = createNode(5, 0);
    root->children[0]->children[1] = createNode(6, 0);

    int returnSize;
    int* result = postorder(root, &returnSize);

    printf("Postorder Traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(root->children[0]->children);
    free(root->children);
    free(root);

    return 0;
}
