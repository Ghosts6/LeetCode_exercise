from typing import Optional

class ListNode:
    def __init__(self, val: int = 0, next: Optional['ListNode'] = None):
        self.val = val
        self.next = next

    def __repr__(self):
        return f"{self.val} -> {self.next}"

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """
        Sorts a singly linked list using insertion sort algorithm.

        Args:
            head: The head of the singly linked list.

        Returns:
            The head of the sorted linked list.
        """
        dummy = ListNode(0)
        current = head
        while current:
            prev = dummy
            while prev.next and prev.next.val < current.val:
                prev = prev.next
            next_temp = current.next
            current.next = prev.next
            prev.next = current
            current = next_temp
        return dummy.next

def build_linked_list(values):
    dummy = ListNode(0)
    current = dummy
    for val in values:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Test case
if __name__ == "__main__":
    solution = Solution()
    # case 1
    head1 = build_linked_list([4, 2, 1, 3])
    sorted_head1 = solution.insertionSortList(head1)
    print(f"result of test case 1 : {linked_list_to_list(sorted_head1)}")  # Expected Output: [1, 2, 3, 4]

    # case 2
    head2 = build_linked_list([-1, 5, 3, 4, 0])
    sorted_head2 = solution.insertionSortList(head2)
    print(f"result of test case 2 : {linked_list_to_list(sorted_head2)}")  # Expected Output: [-1, 0, 3, 4, 5]
