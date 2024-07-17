class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None

        if root == p or root == q:
            return root

        left_lca = self.lowestCommonAncestor(root.left, p, q)
        right_lca = self.lowestCommonAncestor(root.right, p, q)

        if left_lca and right_lca:
            return root

        return left_lca if left_lca else right_lca

def create_tree(values, index=0):
    if index < len(values) and values[index] is not None:
        node = TreeNode(values[index])
        node.left = create_tree(values, 2*index + 1)
        node.right = create_tree(values, 2*index + 2)
        return node
    return None

# test case
if __name__ == "__main__":
    values = [3, 5, 1, 6, 2, 0, 8, None, None, 7, 4]
    root = create_tree(values)

    p = root.left
    q = root.left.right.right  
    solution = Solution()

    lca = solution.lowestCommonAncestor(root, p, q)

    print(f"The LCA of nodes {p.val} and {q.val} is node with value {lca.val}.")