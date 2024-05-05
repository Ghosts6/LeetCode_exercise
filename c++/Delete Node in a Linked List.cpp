#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
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
    head->next->next->next = new ListNode(4);
    ListNode* nodeToDelete = head->next;
    std::cout << "Original list before deletion: ";
    printList(head);
    Solution sol;
    sol.deleteNode(nodeToDelete);
    std::cout << "Result (list after deletion): ";
    printList(head);
    // Clean up memory
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}

