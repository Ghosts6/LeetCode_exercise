import math

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def insertGreatestCommonDivisors(self, head: ListNode) -> ListNode:
        curr = head
        while curr is not None and curr.next is not None:
            gcd_val = math.gcd(curr.val, curr.next.val)
            gcd_node = ListNode(gcd_val)
            gcd_node.next = curr.next
            curr.next = gcd_node
            curr = gcd_node.next
        return head

def list_to_linkedlist(lst):
    if not lst:
        return None
    head = ListNode(lst[0])
    current = head
    for val in lst[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def linkedlist_to_list(node):
    result = []
    current = node
    while current:
        result.append(current.val)
        current = current.next
    return result

# Test cases
if __name__ == "__main__":
    # case 1
    input_list = [24, 36, 48]
    head = list_to_linkedlist(input_list)
    solution = Solution()
    modified_head = solution.insertGreatestCommonDivisors(head)
    print(linkedlist_to_list(modified_head))  # Expected: [24, 12, 36, 12, 48]

    # case 2
    input_list = [15, 10, 5]
    head = list_to_linkedlist(input_list)
    modified_head = solution.insertGreatestCommonDivisors(head)
    print(linkedlist_to_list(modified_head))  # Expected: [15, 5, 10, 5, 5]
