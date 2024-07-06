#include <vector>
#include <algorithm>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            delete head;
            return nullptr;
        }

        ListNode *slow = head, *fast = head, *prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        delete slow;
        
        return head;
    }
};

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy; 
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    std::cout << "Original list: ";
    printLinkedList(head);

    Solution sol;
    head = sol.deleteMiddle(head);

    std::cout << "After deleting middle node: ";
    printLinkedList(head);

    return 0;
}
