#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(const std::vector<int>& A, const std::vector<int>& B) {
        int n = A.size();
        std::vector<int> C(n, 0);
        std::unordered_set<int> seen;
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            if (seen.count(A[i])) {
                ++commonCount;
            } else {
                seen.insert(A[i]);
            }

            if (seen.count(B[i])) {
                ++commonCount;
            } else {
                seen.insert(B[i]);
            }

            C[i] = commonCount;
        }

        return C;
    }
};

// Test cases
int main() {
    Solution solution;
    // case 1
    std::vector<int> A1 = {1, 3, 2, 4};
    std::vector<int> B1 = {0, 2, 3, 4};
    std::vector<int> result1 = solution.findThePrefixCommonArray(A1 ,B1);
    std::cout << "Output of test case 1:" << std::endl;
    for (int num : result1) {
        std::cout << num << " ";
    }
    std:: cout << std::endl;

    // case 2
    std::vector<int> A2 = {2, 3, 1};
    std::vector<int> B2 = {3, 1, 2};
    std::vector<int> result2 = solution.findThePrefixCommonArray(A2 ,B2);
    std::cout << "Output of test case 2:" << std::endl;
    for (int num : result2) {
        std::cout << num << " ";
    }
    std:: cout << std::endl;

    return 0;
}
