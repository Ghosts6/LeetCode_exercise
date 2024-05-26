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