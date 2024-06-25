# 📜 Binary Search Tree to Greater Sum Tree

## 💡 Intuition

The problem is to transform a Binary Search Tree (BST) into a Greater Sum Tree (GST). In a GST, each node's value is replaced with the sum of all node values greater than or equal to it in the original BST. The key insight is to perform a reverse in-order traversal (right-root-left) of the BST. This traversal allows us to process nodes in decreasing order, which helps in accumulating the sum as we go.

## 🛠️ Approach

1.  Reverse In-order Traversal:
Start by traversing the right subtree, which contains larger values.
Accumulate the node values in a running sum.
Update the current node's value to this running sum.
Traverse the left subtree, which contains smaller values.

2.  Recursive Function:
The recursive function bstToGst(TreeNode* root, int& sum) is used to traverse the tree and update the node values.
The base case is when the node is null, where the function simply returns.
Traverse the right subtree first to handle larger values.
Update the current node's value by adding it to the running sum.
Traverse the left subtree to handle smaller values.

3.  Main Function:
Initialize the running sum to zero.
Call the recursive function starting from the root.
Return the modified tree.

## ⏰ Complexity
- Time complexity:
Each node in the tree is visited exactly once during the traversal, where n is the number of nodes in the tree. Thus, the time complexity is O(n).

- Space complexity:
The space complexity is O(h), where h is the height of the tree. This is due to the recursive call stack used during the traversal. In the worst case, the height of the tree could be 
n (if the tree is a linear chain), resulting in O(n) space complexity. For a balanced tree, the height is 
O(logn).

## 💻 Code
### C++
```cpp
class Solution {
public:
    void bstToGst(TreeNode* root, int& sum) {
        if (!root) return;
        bstToGst(root->right, sum);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGst(root, sum);
        return root;
    }
};
```
### C
```c
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
```
### Python 
```py
class Solution:
    def bstToGst(self, root):
        def bst_to_gst(node, acc_sum):
            if not node:
                return acc_sum
            acc_sum = bst_to_gst(node.right, acc_sum)
            acc_sum += node.val
            node.val = acc_sum
            acc_sum = bst_to_gst(node.left, acc_sum)
            return acc_sum
        
        bst_to_gst(root, 0)
        return root
```