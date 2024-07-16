class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findPath(self, root, value, path):
        if not root:
            return False
        if root.val == value:
            return True

        path.append('L')
        if self.findPath(root.left, value, path):
            return True
        path.pop()

        path.append('R')
        if self.findPath(root.right, value, path):
            return True
        path.pop()
        
        return False
    
    def getDirections(self, root: TreeNode, startValue: int, destValue: int) -> str:
        startPath, destPath = [], []
        self.findPath(root, startValue, startPath)
        self.findPath(root, destValue, destPath)
        
        i = 0
        while i < len(startPath) and i < len(destPath) and startPath[i] == destPath[i]:
            i += 1

        steps_up = 'U' * (len(startPath) - i)
        steps_to_dest = ''.join(destPath[i:])
        
        return steps_up + steps_to_dest

# Test case
def test_getDirections():
    root = TreeNode(5)
    root.left = TreeNode(1)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(4)
    
    solution = Solution()
    result = solution.getDirections(root, 3, 6)
    print(f"Test case result: {result}")  

test_getDirections()
