class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def modifiedList(self, nums: list[int], head: ListNode) -> ListNode:
        nums_set = set(nums)

        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next:
            if current.next.val in nums_set:
                current.next = current.next.next
            else:
                current = current.next
  
        return dummy.next

def create_linked_list(arr):
    dummy = ListNode(0)
    current = dummy
    for val in arr:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

def linked_list_to_list(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Test cases
def test_solution():
    sol = Solution()
    
    # case 1
    nums = [1, 2, 3]
    head = create_linked_list([1, 2, 3, 4, 5])
    result = sol.modifiedList(nums, head)
    assert linked_list_to_list(result) == [4, 5], f"Test 1 failed: got {linked_list_to_list(result)}"
    
    # case 2
    nums = [1]
    head = create_linked_list([1, 2, 1, 2, 1, 2])
    result = sol.modifiedList(nums, head)
    assert linked_list_to_list(result) == [2, 2, 2], f"Test 2 failed: got {linked_list_to_list(result)}"
    
    # case 3 
    nums = [1, 2, 3, 4, 5]
    head = create_linked_list([1, 2, 3, 4, 5])
    result = sol.modifiedList(nums, head)
    assert linked_list_to_list(result) == [], f"Test 3 failed: got {linked_list_to_list(result)}"
       
    print("All test cases passed!")

test_solution()
