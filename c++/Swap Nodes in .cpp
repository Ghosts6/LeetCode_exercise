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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
        }
        
        return dummy->next;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
// test case
int main() {
    // create node for test
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    std::cout << "Original list: ";
    printList(head);

    ListNode* swappedHead = sol.swapPairs(head);
    std::cout << "After swapping pairs: ";
    printList(swappedHead);

    return 0;
}
