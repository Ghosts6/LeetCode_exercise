## Intuition & Approach
in the given C++ code, the goal is to insert a new node between every two consecutive nodes in a singly linked list. The value of the new node is the greatest common divisor (GCD) of the values of the two consecutive nodes. The approach is broken down into the following steps:

1.  Traversal of Linked List: The algorithm iterates through the linked list while the current node (curr) and the next node (curr->next) exist.

2.  GCD Calculation: For every pair of consecutive nodes, the GCD of their values is computed using the helper function greatest_common_divisors.

3.  Node Insertion: A new node with the GCD value is created and inserted between the two nodes.

4.  Moving the Pointer: After inserting the new node, the pointer moves two steps forward—first to the newly inserted node's next, which is the original next node.

## Complexity
- Time complexity:O(n)
- Space complexity:O(1)

## Code
```cpp []
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* greatest_common_divisorsNode = new ListNode(greatest_common_divisors(curr->val, curr->next->val));
            greatest_common_divisorsNode->next = curr->next;
            curr->next = greatest_common_divisorsNode;
            curr = greatest_common_divisorsNode->next;
        }
        return head;
    }
private:
    int greatest_common_divisors(int a, int b) {
        if (b == 0) return a;
        return greatest_common_divisors(b, a % b);
    }
};
```
```python3 []
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
```