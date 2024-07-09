# 📜 Maximum Depth of Binary Tree

## 💡 Intuition
The problem at hand is to find the maximum depth of a binary tree, which is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

## 🛠️ Approach
To solve this problem, we can use a recursive approach:

1.  Base Case: If the root node is None (i.e., the tree is empty), the depth is 0.

2.  Recursive Case: For a non-empty tree, the maximum depth is determined by adding 1 to the maximum of the depths of the left and right subtrees.

Here’s how the recursive function works:

For each node, compute the maximum depth of its left subtree (left_depth) and its right subtree (right_depth).
The depth of the current node is then the maximum of these two depths plus one (max(left_depth, right_depth) + 1).

## ⏰ Complexity
- Time complexity:
O(n), where n is the number of nodes in the binary tree. This is because the function visits each node exactly once.

- Space complexity:
O(h), where h is the height of the binary tree. In the worst case, the space complexity due to recursion is O(h) as it will recurse all the way down to the deepest leaf node.

## 💻 Code
```python3 []
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        return max(left_depth, right_depth) + 1
```
```C++ []
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
```