class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.subtree_heights = {}
        self.max_height = 0  
    
    def calculate_subtree_heights(self, node):
        if not node:
            return -1
        
        left_height = self.calculate_subtree_heights(node.left)
        right_height = self.calculate_subtree_heights(node.right)
        
        current_height = max(left_height, right_height) + 1
        self.subtree_heights[node.val] = current_height
        return current_height

    def max_height_excluding_subtree(self, node, exclude_val, current_height):
        if not node:
            return -1

        if node.val == exclude_val:
            return -1
 
        left_height = self.max_height_excluding_subtree(node.left, exclude_val, current_height + 1)
        right_height = self.max_height_excluding_subtree(node.right, exclude_val, current_height + 1)

        return max(left_height, right_height) + 1

    def treeQueries(self, root, queries):
        self.max_height = self.calculate_subtree_heights(root)
        
        answer = []
        for query in queries:
            height_without_subtree = self.max_height_excluding_subtree(root, query, 0)
            answer.append(height_without_subtree)
        
        return answer

# Test cases
if __name__ == "__main__":    
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(4)
    root.left.left = TreeNode(2)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(5)
    root.right.right.right = TreeNode(7)

    solution = Solution()
    print(solution.treeQueries(root, [4]))  # Expected output: [2]
    print(solution.treeQueries(root, [3, 2, 4, 8]))  # Expected output
