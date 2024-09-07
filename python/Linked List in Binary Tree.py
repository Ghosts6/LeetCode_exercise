class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        def dfs(head, root):
            if not head:  
                return True
            if not root:  
                return False
            if root.val != head.val:  
                return False
            return dfs(head.next, root.left) or dfs(head.next, root.right)

        def traverse(root):
            if not root:
                return False
            return dfs(head, root) or traverse(root.left) or traverse(root.right)

        return traverse(root)


def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

from collections import deque

def create_binary_tree(arr):
    if not arr:
        return None
    root = TreeNode(arr[0])
    queue = deque([root])
    i = 1
    while i < len(arr):
        current = queue.popleft()
        if arr[i] is not None:
            current.left = TreeNode(arr[i])
            queue.append(current.left)
        i += 1
        if i < len(arr) and arr[i] is not None:
            current.right = TreeNode(arr[i])
            queue.append(current.right)
        i += 1
    return root

# Test cases
solution = Solution()

# case 1
head = create_linked_list([4, 2, 8])
root = create_binary_tree([1, 4, 4, None, 2, 2, None, 1, None, 6, 8, None, None, None, None, 1, 3])
print(solution.isSubPath(head, root))  # Output: True

# case 2
head = create_linked_list([1, 4, 2, 6])
root = create_binary_tree([1, 4, 4, None, 2, 2, None, 1, None, 6, 8, None, None, None, None, 1, 3])
print(solution.isSubPath(head, root))  # Output: True

# case 3
head = create_linked_list([1, 4, 2, 6, 8])
root = create_binary_tree([1, 4, 4, None, 2, 2, None, 1, None, 6, 8, None, None, None, None, 1, 3])
print(solution.isSubPath(head, root))  # Output: False