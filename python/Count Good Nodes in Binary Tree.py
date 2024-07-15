class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, max_val):
            if not node:
                return 0
            total_good = 0
            if node.val >= max_val:
                total_good += 1
            max_val = max(max_val, node.val)
            total_good += dfs(node.left, max_val)
            total_good += dfs(node.right, max_val)
            return total_good
        
        return dfs(root, root.val)

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

# Test case
def test_good_nodes():

    values = [3, 1, 4, None, 3, None, 5]
    root = build_tree(values)

    sol = Solution()

    result = sol.goodNodes(root)
    
    expected = 4
    
    assert result == expected, f"Expected {expected}, but got {result}"
    print("Test passed!")

test_good_nodes()
