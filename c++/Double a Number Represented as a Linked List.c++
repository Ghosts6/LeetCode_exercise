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
    ListNode* doubleIt(ListNode* head) {
        int carry = doubleNodes(head);
        if (carry > 0) {
            head = new ListNode(carry, head);
        }
        return head;
    }

private:
    int doubleNodes(ListNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int doubledValue = node->val * 2 + doubleNodes(node->next);
        node->val = doubledValue % 10;
        return doubledValue / 10;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
//  test case
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution solution;
    ListNode* newHead = solution.doubleIt(head);
    std::cout << "List: ";
    printList(head);
    std::cout << "result: ";
    printList(newHead);
    //clean memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
