class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left

            temp = self.minValueNode(root.right)

            root.val = temp.val

            root.right = self.deleteNode(root.right, temp.val)

        return root

    def minValueNode(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

def inorderTraversal(root):
    return inorderTraversal(root.left) + [root.val] + inorderTraversal(root.right) if root else []
#   test case
if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(7)

    bst = Solution()

    print("In-order traversal of the original tree: ", inorderTraversal(root))

    root = bst.deleteNode(root, 3)

    print("In-order traversal after deleting node with key 3: ", inorderTraversal(root))
