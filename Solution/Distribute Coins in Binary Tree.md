# -Distribute Coins in Binary Tree

# 📜 Problem Description
You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

# 💡 Intuition
The problem involves redistributing coins in a binary tree such that each node has exactly one coin. We aim to minimize the total number of moves required for redistribution.

# 🛠️ Approach
1. We perform a postorder traversal of the binary tree, starting from the bottom.
2. At each node, we calculate the balance of coins (number of coins - 1) in the subtree rooted at that node.
3. We keep track of the total number of moves required by adding the absolute value of the balance to the 'moves' variable.
4. The final value of 'moves' represents the minimum number of moves required to redistribute the coins.

# ⏰ Complexity
- Time complexity:
all the solutions have O(h) space complexity, where h is the height of the binary tree. This is because the space required for the call stack during the postorder traversal is proportional to the height of the tree.

- Space complexity:
all the solutions have O(n) time complexity, where n is the number of nodes in the binary tree. This is because we perform a postorder traversal, visiting each node exactly once.

# 💻 Code
### c++
```cpp
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        postorder(root, moves);
        return moves;
    }
    
private:
    int postorder(TreeNode* node, int& moves) {
        if (!node) return 0;
        int leftBalance = postorder(node->left, moves);
        int rightBalance = postorder(node->right, moves);
        int balance = node->val + leftBalance + rightBalance - 1;
        moves += abs(balance);
        return balance;
    }
};

```
### python3
```py
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.moves = 0
        self.postorder(root)
        return self.moves
    
    def postorder(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        left_balance = self.postorder(node.left)
        right_balance = self.postorder(node.right)
        balance = node.val + left_balance + right_balance - 1
        self.moves += abs(balance)
        return balance
```
### java script
```js
var distributeCoins = function(root) {
    let moves = 0;

    function postorder(node) {
        if (!node) return 0;
        const leftBalance = postorder(node.left);
        const rightBalance = postorder(node.right);
        const balance = node.val + leftBalance + rightBalance - 1;
        moves += Math.abs(balance);
        return balance;
    }

    postorder(root);
    return moves;
};
```