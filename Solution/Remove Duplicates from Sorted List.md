# 📜 Remove Duplicates from Sorted List


# 💡 Intuition
To remove duplicates from a sorted linked list, iterate through the list and compare each node with its next node. If they are the same, remove the next node.

# 🛠️ Approach
Use a single pointer to traverse the list. When duplicates are found, adjust the next pointer of the current node to skip the duplicate node.

# ⏰ Complexity
- Time complexity:O(n), where n is the number of nodes in the linked list. Each node is visited once.


- Space complexity:O(1), as no additional space proportional to the input size is used. Only a few pointers are used for traversal.


# 💻 Code
### c++
```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* current = head;
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* nextNode = current->next->next;
                delete current->next;
                current->next = nextNode;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
```
### c
```c
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* current = head;
    while (current && current->next) {
        if (current->val == current->next->val) {
            struct ListNode* nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
    return head;
}
```
### python
```py
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None

        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        
        return head
```