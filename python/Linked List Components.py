class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def numComponents(self, head: ListNode, nums: list[int]) -> int:
        nums_set = set(nums)  
        count = 0
        in_component = False

        current = head
        while current:
            if current.val in nums_set:
                if not in_component:
                    count += 1
                    in_component = True
            else:
                in_component = False
            current = current.next

        return count

def create_linked_list(values):
    dummy = ListNode(-1)
    current = dummy
    for val in values:
        current.next = ListNode(val)
        current = current.next
    return dummy.next

# Test cases
if __name__ == "__main__":
    # case 1
    head = create_linked_list([0, 1, 2, 3])
    nums = [0, 1, 3]
    solution = Solution()
    print("Test Case 1 Output:", solution.numComponents(head, nums))  # Expected Output: 2

    # case 2
    head = create_linked_list([0, 1, 2, 3, 4])
    nums = [0, 3, 1, 4]
    print("Test Case 2 Output:", solution.numComponents(head, nums))  # Expected Output: 2
