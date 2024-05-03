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

// test case
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution sol;
    ListNode* newHead = sol.insertGreatestCommonDivisors(head);
    while (newHead != nullptr) {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
    }
    return 0;
}
