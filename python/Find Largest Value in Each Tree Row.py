from collections import deque
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        
        result = []
        queue = deque([root])  
        
        while queue:
            level_max = float('-inf')  
            for _ in range(len(queue)):  
                node = queue.popleft()
                level_max = max(level_max, node.val) 
                if node.left:
                    queue.append(node.left)  
                if node.right:
                    queue.append(node.right) 
            result.append(level_max)  
        
        return result

def build_tree(values):
        if not values:
            return None
        nodes = [TreeNode(val) if val is not None else None for val in values]
        kids = nodes[::-1]
        root = kids.pop()
        for node in nodes:
            if node:
                if kids:
                    node.left = kids.pop()
                if kids:
                    node.right = kids.pop()
        return root

# Test cases in main
if __name__ == "__main__":
    # case 1
    root1 = build_tree([1, 3, 2, 5, 3, None, 9])
    solution = Solution()
    print("Test Case 1:", solution.largestValues(root1))  # Output: [1, 3, 9]

    # case 2
    root2 = build_tree([1, 2, 3])
    print("Test Case 2:", solution.largestValues(root2))  # Output: [1, 3]

    # case 3
    root3 = build_tree([])
    print("Test Case 3:", solution.largestValues(root3))  # Output: []
