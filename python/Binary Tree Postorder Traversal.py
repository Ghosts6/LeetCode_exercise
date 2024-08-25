from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

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
    
# Test cases
def run_tests():
    solution = Solution()

    # case 1
    root1 = None
    result1 = solution.postorderTraversal(root1)
    print("Test 1 - Empty Tree:", result1)  # Expected output: []

    # case 2
    root2 = TreeNode(1)
    result2 = solution.postorderTraversal(root2)
    print("Test 2 - Single Node Tree:", result2)  # Expected output: [1]

    # case 3
    root3 = TreeNode(1, TreeNode(2), TreeNode(3))
    result3 = solution.postorderTraversal(root3)
    print("Test 3 - Simple Binary Tree:", result3)  # Expected output: [2, 3, 1]

run_tests()