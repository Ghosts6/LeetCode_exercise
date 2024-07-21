class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return None
        if root.val == val:
            return root
        elif val < root.val:
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)

# test case
def main():
    node5 = TreeNode(5)
    node3 = TreeNode(3)
    node8 = TreeNode(8)
    node1 = TreeNode(1)
    node4 = TreeNode(4)
    node7 = TreeNode(7)
    node10 = TreeNode(10)
    
    node5.left = node3
    node5.right = node8
    node3.left = node1
    node3.right = node4
    node8.left = node7
    node8.right = node10

    sol = Solution()

    val = 8
    result = sol.searchBST(node5, val)
    
    if result:
        print(f"Node with value {val} found.")
    else:
        print(f"Node with value {val} not found.")

    def print_subtree(node):
        if not node:
            return
        print(node.val, end=" ")
        print_subtree(node.left)
        print_subtree(node.right)
    
    if result:
        print("Subtree rooted at the found node:")
        print_subtree(result)

if __name__ == "__main__":
    main()
