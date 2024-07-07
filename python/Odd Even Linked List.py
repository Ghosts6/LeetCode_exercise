class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        
        odd = head
        even = head.next
        even_head = even
        
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next
        
        odd.next = even_head
        return head

def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def linked_list_to_list(head):
    arr = []
    current = head
    while current:
        arr.append(current.val)
        current = current.next
    return arr

# Test case
head = create_linked_list([1, 2, 3, 4, 5])
solution = Solution()
new_head = solution.oddEvenList(head)
print(linked_list_to_list(new_head))  
