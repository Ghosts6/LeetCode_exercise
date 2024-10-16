# 🧮 Insert Greatest Common Divisors in Linked List

## 📋 Problem Statement
Given a singly linked list, the task is to insert a new node between every two consecutive nodes. The value of this new node should be the greatest common divisor (GCD) of the values of those two consecutive nodes.

## 💡 Intuition
The problem can be approached by iterating over the linked list and inserting a node with the GCD value between each consecutive pair of nodes. By breaking down the task into individual steps, we can ensure the insertion process maintains the list structure while meeting the GCD condition.

## 🔄 Approach
The solution involves the following steps:

1. **🔍 Traversing the Linked List**: 
   - We use a pointer (`curr`) to traverse the linked list.
   - We continue the traversal as long as both the current node (`curr`) and its next node (`curr.next`) are not `null`, ensuring we have two consecutive nodes to work with.

2. **🧩 Calculating GCD**: 
   - For each pair of consecutive nodes, we calculate the GCD of their values using a helper function. This function uses the Euclidean algorithm, which is efficient for GCD calculations.

3. **➕ Inserting New Nodes**: 
   - A new node is created with the GCD value and inserted between the current and the next node.
   - This step ensures that we adhere to the problem’s requirement of placing the GCD between each consecutive pair of nodes.

4. **⏩ Moving the Pointer**: 
   - After inserting the new node, we skip to the node following the newly inserted one to continue processing the next pair of nodes.
   - This two-step movement keeps our traversal in sync with the updated list structure.

## 📊 Complexity Analysis
- **⏱ Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the list. This complexity arises because we visit each node once.
- **💾 Space Complexity**: \(O(1)\), as we only use a constant amount of additional space for the pointer and temporary variables.

## 💻 Code
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
```js []
function ListNode(val, next = null) {
    this.val = val;
    this.next = next;
}

function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b);
}

var insertGreatestCommonDivisors = function(head) {
    let curr = head;
    while (curr !== null && curr.next !== null) {
        const gcdValue = gcd(curr.val, curr.next.val);
        const gcdNode = new ListNode(gcdValue);
        
        gcdNode.next = curr.next;
        curr.next = gcdNode;
        
        curr = gcdNode.next;
    }
    return head;
};
```