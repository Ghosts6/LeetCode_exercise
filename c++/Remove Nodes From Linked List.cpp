#include <iostream>
#include <climits>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;   
        while (head != nullptr) {
            while (!stack.empty() && stack.top()->val < head->val) {
                stack.pop();
            }
            stack.push(head);
            head = head->next;
        }      
        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            ListNode* cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        return nxt;
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
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    ListNode* result = sol.removeNodes(head);
    std::cout << "result of test case: ";
    printList(result);
    //clean memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
