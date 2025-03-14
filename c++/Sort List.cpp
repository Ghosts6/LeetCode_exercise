#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head;

            ListNode* mid = getMid(head);
            ListNode* left = head;
            ListNode* right = mid->next;
            mid->next = nullptr;

            left = sortList(left);
            right = sortList(right);
    
            return merge(left, right);
        }
    
    private:
        ListNode* getMid(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head->next;  
            
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;  
        }

        ListNode* merge(ListNode* l1, ListNode* l2) {
            ListNode dummy(0);
            ListNode* tail = &dummy;
            
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    tail->next = l1;
                    l1 = l1->next;
                } else {
                    tail->next = l2;
                    l2 = l2->next;
                }
                tail = tail->next;
            }
            
            tail->next = l1 ? l1 : l2; 
            return dummy.next;
        }
    };
    

// Test cases
int main() {
    Solution s;

    // case 1
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode* result1 = s.sortList(head);
    
    std::cout << "Case 1: ";
    while (result1) {
        std::cout << result1->val << " "; // Expected output: 1 2 3 4
        result1 = result1->next;
    }
    
    // case 2
    ListNode* head2 = new ListNode(-1);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(0);
    ListNode* result2 = s.sortList(head2);

    std::cout << "\nCase 2: ";
    while (result2) {
        std::cout << result2->val << " "; // Expected output: -1 0 3 4 5
        result2 = result2->next;
    }
 
    return 0;
}