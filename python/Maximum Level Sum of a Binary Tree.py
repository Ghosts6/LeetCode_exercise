from collections import deque, defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        if not root:
            return 0

        level_sums = defaultdict(int)
        max_sum = float('-inf')
        min_level = 1

        queue = deque([(root, 1)])

        while queue:
            node, level = queue.popleft()
            level_sums[level] += node.val

            if node.left:
                queue.append((node.left, level + 1))
            if node.right:
                queue.append((node.right, level + 1))

        for level in level_sums:
            if level_sums[level] > max_sum:
                max_sum = level_sums[level]
                min_level = level

        return min_level

# Test case
def build_tree(values):
    if not values:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1
    while i < len(values):
        node = queue.popleft()
        if values[i] is not None:
            node.left = TreeNode(values[i])
            queue.append(node.left)
        i += 1
        if i < len(values) and values[i] is not None:
            node.right = TreeNode(values[i])
            queue.append(node.right)
        i += 1

    return root

values = [1, 7, 0, 7, -8, None, None]
root = build_tree(values)
solution = Solution()
print("result of test case :", solution.maxLevelSum(root))
