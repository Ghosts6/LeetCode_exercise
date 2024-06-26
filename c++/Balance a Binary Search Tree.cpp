#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void inOrderTraversal(TreeNode* root, std::vector<int>& nodes) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inOrderTraversal(root->right, nodes);
    }

    TreeNode* sortedArrayToBST(const std::vector<int>& nodes, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = sortedArrayToBST(nodes, left, mid - 1);
        node->right = sortedArrayToBST(nodes, mid + 1, right);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> nodes;
        inOrderTraversal(root, nodes);
        return sortedArrayToBST(nodes, 0, nodes.size() - 1);
    }
};

void printInOrder(TreeNode* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

//  test case
int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    
    std::cout << "Original BST (In-order): ";
    printInOrder(root);
    std::cout << std::endl;
    
    TreeNode* balancedRoot = solution.balanceBST(root);
    
    std::cout << "Balanced BST (In-order): ";
    printInOrder(balancedRoot);
    std::cout << std::endl;

    delete root->right->right->right->right;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;
    
    delete balancedRoot->left->left;
    delete balancedRoot->left;
    delete balancedRoot->right->right;
    delete balancedRoot->right;
    delete balancedRoot;
    
    return 0;
}
