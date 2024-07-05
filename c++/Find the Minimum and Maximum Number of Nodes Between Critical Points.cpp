#include <iostream>
#include <vector>
#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::vector<int> criticalPoints;
        int pos = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                criticalPoints.push_back(pos);
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        int maxDist = criticalPoints.back() - criticalPoints.front();

        for (size_t i = 1; i < criticalPoints.size(); ++i) {
            minDist = std::min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDist, maxDist};
    }
};

ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

void printResult(const std::vector<int>& result) {
    std::cout << "[" << result[0] << ", " << result[1] << "]\n";
}
//  test case
int main() {
    std::vector<int> values = {5, 3, 1, 2, 5, 1, 2};
    ListNode* head = createLinkedList(values);

    Solution sol;
    std::vector<int> result = sol.nodesBetweenCriticalPoints(head);

    printResult(result);

    return 0;
}
