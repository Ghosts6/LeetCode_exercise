# - Remove Nodes From Linked List

# 📜 Problem Description

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.
# 💡 Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires traversing the linked list and removing nodes that have a greater value anywhere to their right. One approach could be using a stack to keep track of nodes in non-decreasing order of their values.
# 🛠️ Approach
<!-- Describe your approach to solving the problem. -->
Traverse the linked list while maintaining a stack.
At each node, compare its value with the values of nodes at the top of the stack. If the value of the current node is greater, pop nodes from the stack until the top node's value is greater or equal.Push the current node onto the stack.After traversing the entire linked list, construct the modified linked list from the elements in the stack.

# ⏰ Complexity

Time complexity:
        C++: O(n)O(n)
        Python: O(n)O(n)
        JavaScript: O(n)O(n)
(where nn is the number of nodes in the linked list)

Space complexity:
        C++: O(n)O(n)
        Python: O(n)O(n)
        JavaScript: O(n)O(n)

(where nn is the number of nodes in the linked list)

# 💻 Code
### C++
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;   
        while (head != nullptr) {
            while (!stack.empty() && stack.top()->val < head->val) {
                stack.pop();
            }
            stack.push(head);
            head = head->next;
        }      
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            ListNode* cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        return nxt;
    }
};
```
### python
```python
class Solution:
    def removeNodes(self, head: ListNode) -> ListNode:
        stack = []
        while head:
            while stack and stack[-1].val < head.val:
                stack.pop()
            stack.append(head)
            head = head.next
        nxt = None
        while stack:
            cur = stack.pop()
            cur.next = nxt
            nxt = cur
        return nxt
```
### JavaScript
```JavaScript
class Solution {
    removeNodes(head) {
        const stack = [];
        while (head) {
            while (stack.length && stack[stack.length - 1].val < head.val) {
                stack.pop();
            }
            stack.push(head);
            head = head.next;
        }
        let nxt = null;
        while (stack.length) {
            const cur = stack.pop();
            cur.next = nxt;
            nxt = cur;
        }
        return nxt;
    }
}
```