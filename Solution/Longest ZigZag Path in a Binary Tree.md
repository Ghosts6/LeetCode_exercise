# 📜 Longest ZigZag Path in a Binary Tree


## 💡 Intuition
The zigzag path alternates between left and right child nodes. By keeping track of the direction and the length of the current zigzag path, we can explore all possible zigzag paths in the tree.
Each time we change direction, we increment the length; otherwise, we start a new path.
Using a DFS approach allows us to explore each node and its potential zigzag path efficiently.

## 🛠️ Approach
1.  TreeNode Definition: We start by defining the TreeNode structure, similar to the Python version.
2.  Solution Class: Create a Solution class that holds the maximum zigzag length as a member variable.
3.  DFS Helper Function: Implement a helper function using Depth-First Search (DFS) to traverse the tree.
The helper function takes the current node, the direction of movement, and the current length of the zigzag path.
If the node is null, it returns.
Update the maximum zigzag length if the current length is greater.
Recursively call the helper function for left and right children based on the current direction.
4.  Initial DFS Calls: Start DFS from the root node for both left and right directions with an initial length of 0.
5.  Return Result: Finally, return the maximum length found.


## ⏰ Complexity
- Time complexity:
O(N), where N is the number of nodes in the tree, because we visit each node once.

- Space complexity:
O(H), where H is the height of the tree due to the recursion stack.


## 💻 Code
```python []
class Solution:
    def __init__(self):
        self.max_length = 0

    def longestZigZag(self, root: TreeNode) -> int:
        def dfs(node: TreeNode, direction: str, length: int):
            if not node:
                return

            self.max_length = max(self.max_length, length)

            if direction == 'left':
                dfs(node.left, 'right', length + 1)  
                dfs(node.right, 'left', 1)           
            else:
                dfs(node.right, 'left', length + 1)  
                dfs(node.left, 'right', 1)          

        dfs(root, 'left', 0)
        dfs(root, 'right', 0)
        
        return self.max_length
```
```C++ []
class Solution {
public:
    int max_length;

    Solution() : max_length(0) {}

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;

        max_length = std::max(max_length, length);

        if (isLeft) {
            dfs(node->left, false, length + 1);
            dfs(node->right, true, 1);        
        } else {
            dfs(node->right, true, length + 1); 
            dfs(node->left, false, 1);          
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);  
        dfs(root, false, 0); 
        return max_length;
    }
};
```