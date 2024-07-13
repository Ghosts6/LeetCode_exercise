class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getLeaves(self, root: TreeNode) -> list:
        leaves = []
        self._collectLeaves(root, leaves)
        return leaves
    
    def _collectLeaves(self, node: TreeNode, leaves: list):
        if not node:
            return
        if not node.left and not node.right:
            leaves.append(node.val)
        if node.left:
            self._collectLeaves(node.left, leaves)
        if node.right:
            self._collectLeaves(node.right, leaves)
    
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        return self.getLeaves(root1) == self.getLeaves(root2)

# Test case
root1 = TreeNode(3)
root1.left = TreeNode(5)
root1.right = TreeNode(1)
root1.left.left = TreeNode(6)
root1.left.right = TreeNode(2)
root1.left.right.left = TreeNode(7)
root1.left.right.right = TreeNode(4)
root1.right.left = TreeNode(9)
root1.right.right = TreeNode(8)

root2 = TreeNode(3)
root2.left = TreeNode(5)
root2.right = TreeNode(1)
root2.left.left = TreeNode(6)
root2.left.right = TreeNode(2)
root2.left.right.left = TreeNode(7)
root2.left.right.right = TreeNode(4)
root2.right.left = TreeNode(9)
root2.right.right = TreeNode(8)

solution = Solution()
print(solution.leafSimilar(root1, root2))  
