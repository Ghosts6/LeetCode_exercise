class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def splitListToParts(self, head: ListNode, k: int):
        length = 0
        current = head
        while current:
            length += 1
            current = current.next

        part_size = length // k  
        remainder = length % k   

        parts = []
        current = head
        
        for i in range(k):
            part_head = current  
            part_length = part_size + (1 if i < remainder else 0)

            for j in range(part_length - 1):
                if current:
                    current = current.next

            if current:
                next_part = current.next
                current.next = None  # Disconnect
                current = next_part

            parts.append(part_head)
        
        return parts

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
    while node:
        result.append(node.val)
        node = node.next
    return result

# case 1
head = list_to_linkedlist([1, 2, 3])
k = 5
solution = Solution()
result = solution.splitListToParts(head, k)
for part in result:
    print(linkedlist_to_list(part))  # Expected output: [[1], [2], [3], [], []]

# case 2
head = list_to_linkedlist([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
k = 3
result = solution.splitListToParts(head, k)
for part in result:
    print(linkedlist_to_list(part))  # Expected output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]

# case 3
head = list_to_linkedlist([])
k = 3
result = solution.splitListToParts(head, k)
for part in result:
    print(linkedlist_to_list(part))  # Expected output: [[], [], []]
