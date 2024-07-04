#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);  
        ListNode* current = dummy;
        ListNode* iterator = head->next;  
        
        int sum = 0;
        while (iterator != nullptr) {
            if (iterator->val == 0) {
                if (sum > 0) {
                    current->next = new ListNode(sum);
                    current = current->next;
                    sum = 0;
                }
            } else {
                sum += iterator->val;
            }
            iterator = iterator->next;
        }
        
        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Test case
int main() {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0tNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    Solution solution;
    ListNode* modifiedHead = solution.mergeNodes(head);
    
    printList(modifiedHead);

    return 0;
}

