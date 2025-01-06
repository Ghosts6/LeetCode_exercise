#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
    std::vector<int> minOperations(const std::string& boxes) {
        int n = boxes.size();
        std::vector<int> result(n, 0);

        int moves = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            result[i] += moves;
            count += boxes[i] == '1' ? 1 : 0;
            moves += count;
        }

        moves = 0, count = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += moves;
            count += boxes[i] == '1' ? 1 : 0;
            moves += count;
        }

        return result;
    }
};
// Test cases
int main() {
    Solution solution;
    // case 1
    std::string boxes1 = "110";
    std::vector<int> result1 = solution.minOperations(boxes1);
    std::cout << "Out put of test case 1:" << std::endl; 
    for(int num : result1) std::cout << num << " "; // Expected Out Put: 1,1,3 
    std::cout << std::endl;
    // case 2
    std::string boxes2 = "001011";
    std::vector<int> result2 = solution.minOperations(boxes2);
    std::cout << "Out put of test case 1:" << std::endl;
    for(int num : result2) std::cout << num << " "; // Expected Out Put: 11,8,5,4,3,4
    std::cout << std::endl;

    return 0;
}