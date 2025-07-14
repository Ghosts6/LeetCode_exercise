from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        result = 0
        while head:
            result = (result << 1) | head.val
            head = head.next
        return result

# Helper function to build a linked list from a list
def build_linked_list(values):
    dummy = ListNode()
    current = dummy
    for v in values:
        current.next = ListNode(v)
        current = current.next
    return dummy.next

# Test cases
if __name__ == "__main__":
    solution = Solution()

    head1 = build_linked_list([1, 0, 1])
    print(f"Result of test case1 : {solution.getDecimalValue(head1)}")  # Output: 5

    head2 = build_linked_list([0])
    print(f"Result of test case2 : {solution.getDecimalValue(head2)}")  # Output: 0

