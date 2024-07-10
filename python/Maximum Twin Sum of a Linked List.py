class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def pairSum(self, head: ListNode) -> int:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        prev = None
        curr = slow
        while curr:
            next_temp = curr.next
            curr.next = prev
            prev = curr
            curr = next_temp

        max_twin_sum = 0
        first_half = head
        second_half = prev
        while second_half:
            max_twin_sum = max(max_twin_sum, first_half.val + second_half.val)
            first_half = first_half.next
            second_half = second_half.next

        return max_twin_sum

def create_linked_list(lst):
    dummy = ListNode()
    current = dummy
    for value in lst:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

# Test case
lst = [1, 2, 3, 4]
head = create_linked_list(lst)
solution = Solution()
print(solution.pairSum(head))  