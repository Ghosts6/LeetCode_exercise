class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

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

# Test case
def test_longestZigZag():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(4)
    root.left.right.left = TreeNode(6)
    root.right.right = TreeNode(5)
    root.right.right.right = TreeNode(7)

    solution = Solution()

    result = solution.longestZigZag(root)

    print(f"Test case result: {result}")

test_longestZigZag()
