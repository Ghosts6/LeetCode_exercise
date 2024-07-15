from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        def dfs(node, current_sum):
            nonlocal count
            if not node:
                return

            current_sum += node.val

            count += prefix_sums[current_sum - targetSum]

            prefix_sums[current_sum] += 1
            
            dfs(node.left, current_sum)
            dfs(node.right, current_sum)

            prefix_sums[current_sum] -= 1
        
        count = 0
        prefix_sums = defaultdict(int)
        prefix_sums[0] = 1  
        
        dfs(root, 0)
        
        return count

#  test case
if __name__ == "__main__":
    root = TreeNode(10)
    root.left = TreeNode(5)
    root.right = TreeNode(-3)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(2)
    root.right.right = TreeNode(11)
    root.left.left.left = TreeNode(3)
    root.left.left.right = TreeNode(-2)
    root.left.right.right = TreeNode(1)

    sol = Solution()
 
    targetSum = 8

    result = sol.pathSum(root, targetSum)
    print(f"The number of paths that sum to {targetSum} is: {result}")
