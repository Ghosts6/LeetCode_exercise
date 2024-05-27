#include <iostream>
#include <algorithm>
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

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// test case
int main() {
    std::vector<int> values = {1, 1, 2, 3, 3};
    ListNode* head = createList(values);
    std::cout << "Original list: ";
    printList(head);
    Solution solution;
    head = solution.deleteDuplicates(head);

    std::cout << "list after removing duplicates: ";
    printList(head);

    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
