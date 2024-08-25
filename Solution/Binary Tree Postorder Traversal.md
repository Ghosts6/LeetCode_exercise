# 📜 Binary Tree Postorder Traversal

## 💡 Intuition
Postorder Traversal of a Binary Tree
What is Postorder Traversal?
Postorder Traversal is a way of visiting all the nodes in a binary tree. 

The order of visiting nodes in postorder traversal is:
	1.	Left subtree
	2.	Right subtree
	3.	Root node

Imagine you are reading a book from the back to the front. You start with the last chapter, then the second-to-last, and so on until you reach the first chapter. Similarly, in postorder traversal, you visit the “children” of a node first (left and right), and then you visit the node itself.

## 🛠️ Approach
1.  Stack-Based Iterative Postorder Traversal:
We simulate the postorder traversal by pushing the root node onto the stack.
In each iteration, we pop the top node, insert its value at the beginning of the result list (this effectively reverses the order of processing).
We then push the left and right children of the current node onto the stack (right first, so left is processed first).
The key here is inserting the node’s value at the beginning of the list, which gives us the postorder (left-right-root) traversal.

## ⏰ Complexity
- Time complexity:
The algorithm visits each node exactly once and performs a constant amount of work for each node. Therefore, the time complexity is O(N), where N is the number of nodes in the tree.

- Space complexity:
The space complexity is primarily determined by the stack, which holds at most O(H) nodes, where H is the height of the tree. In the worst case, for a skewed tree, H can be N, so the space complexity is O(N). However, for a balanced tree, the space complexity is O(log N).

## 💻 Code
```cpp []
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == nullptr) return result;

        std::stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* curr = nodes.top();
            nodes.pop();
            result.insert(result.begin(), curr->val);

            if (curr->left != nullptr) {
                nodes.push(curr->left);
            }
            if (curr->right != nullptr) {
                nodes.push(curr->right);
            }
        }

        return result;
    }
};
```
```python []
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        if root is None:
            return result

        nodes = [root]

        while nodes:
            curr = nodes.pop()
            result.insert(0, curr.val)

            if curr.left is not None:
                nodes.append(curr.left)
            if curr.right is not None:
                nodes.append(curr.right)

        return result
```