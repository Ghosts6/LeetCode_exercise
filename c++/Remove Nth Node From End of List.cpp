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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        
        for (int i = 0; i < n + 1; ++i) {
            if (!fast) return nullptr;
            fast = fast->next;
        }
        
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy.next;
    }
};

void printList(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// test case
int main() {
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode *newHead = sol.removeNthFromEnd(head, n); // Expected output: 1 2 3 5
    printList(newHead);   
    return 0;
}
