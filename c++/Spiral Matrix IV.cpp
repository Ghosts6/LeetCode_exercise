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
    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (head != nullptr && top <= bottom && left <= right) {
            for (int i = left; i <= right && head != nullptr; ++i) {
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;

            for (int i = top; i <= bottom && head != nullptr; ++i) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;

            for (int i = right; i >= left && head != nullptr; --i) {
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;

            for (int i = bottom; i >= top && head != nullptr; --i) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return matrix;
    }
};

ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
//  Test cases
int main() {
    // case 1
    int m1 = 3, n1 = 5;
    std::vector<int> values1 = {3, 0, 2, 6, 8, 1, 7, 9, 4, 2, 5, 5, 0};
    ListNode* head1 = createLinkedList(values1);
    
    Solution sol;
    std::vector<std::vector<int>> result1 = sol.spiralMatrix(m1, n1, head1);
    
    std::cout << "result of case 1:" << std::endl;
    printMatrix(result1);
    
    // case 2
    int m2 = 1, n2 = 4;
    std::vector<int> values2 = {0, 1, 2};
    ListNode* head2 = createLinkedList(values2);
    
    std::vector<std::vector<int>> result2 = sol.spiralMatrix(m2, n2, head2);
    
    std::cout << "result of case 2 :" << std::endl;
    printMatrix(result2);

    return 0;
}
