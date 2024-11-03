class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        def count_nodes(start):
            count = 0
            while start:
                count += 1
                start = start.next
            return count

        if not head or k == 1:
            return head
 
        node_count = count_nodes(head)
        dummy = ListNode(0)
        dummy.next = head
        prev_group_end = dummy
        
        while node_count >= k:
            current = prev_group_end.next
            next_node = current.next
            for _ in range(1, k):
                current.next = next_node.next
                next_node.next = prev_group_end.next
                prev_group_end.next = next_node
                next_node = current.next

            prev_group_end = current
            node_count -= k
        
        return dummy.next

# Helper functions
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

def print_linked_list(head):
    values = []
    while head:
        values.append(head.val)
        head = head.next
    print(values)

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        ([1, 2, 3, 4, 5], 2, "Reversed list for k = 2:"),  # Expected output: [2, 1, 4, 3, 5]
        ([1, 2, 3, 4, 5], 3, "Reversed list for k = 3:")   # Expected output: [3, 2, 1, 4, 5]
    ]

    for values, k, message in test_cases:
        head = create_linked_list(values)
        result = solution.reverseKGroup(head, k)
        print(message)
        print_linked_list(result)

