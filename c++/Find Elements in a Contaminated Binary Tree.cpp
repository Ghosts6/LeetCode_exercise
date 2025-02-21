#include <iostream>
#include <unordered_set>

struct TreeNode {
     	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    std::unordered_set<int> values;

    void recover(TreeNode* node, int val) {
        if (!node) return;
        node->val = val;
        values.insert(val);
        recover(node->left, 2 * val + 1);
        recover(node->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode* root) {
        if (root) recover(root, 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

// Test case
int main() {
    TreeNode* root = new TreeNode(-1, nullptr, new TreeNode(-1));
    FindElements findElements(root);
    
    std::cout << std::boolalpha;
	// case 1
    std::cout << findElements.find(1) << "\n";  // Expected Output:false
	// case 2
    std::cout << findElements.find(2) << "\n";  // Expected Output:true

    return 0;
}